/*
 * @Author: yjy 3253932102@qq.com
 * @Date: 2024-06-07 23:52:26
 * @LastEditors: yjy 3253932102@qq.com
 * @LastEditTime: 2024-06-08 20:29:20
 * @FilePath: /mpu6050/components/nv3030b/nv3030b_sof_drv.c
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "nv3030b_sof_drv.h"
#include "esp_log.h"    

#define TAG "NV3030B"



#define GPIO_OUTPUT_PIN_SEL  ((1ULL << scl_sof_gpio) | (1ULL << sda_sof_gpio) | (1ULL << res_sof_gpio) | (1ULL << dc_sof_gpio) | (1ULL << cs_sof_gpio) | (1ULL << blk_sof_gpio) )

void LCD_GPIO_Init(void)
{
    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = 0;
    io_conf.pull_down_en = 0;
    gpio_config(&io_conf);
}

void LCD_Writ_Bus(uint8_t dat)
{
    uint8_t i;
    LCD_CS_Clr();
    for(i = 0; i < 8; i++)
    {
        LCD_SCLK_Clr();
        if(dat&0x80)
            LCD_MOSI_Set();
        else
            LCD_MOSI_Clr(); 
        LCD_SCLK_Set();
        dat<<=1;

    }
    LCD_CS_Set();
}

void LCD_WR_DATA8(uint8_t dat)
{
    LCD_Writ_Bus(dat);
}

void LCD_WR_DATA(uint16_t dat)
{
    LCD_Writ_Bus(dat>>8);
    LCD_Writ_Bus(dat);
}

void LCD_WR_REG(uint16_t dat)
{
    LCD_DC_Clr();   //write command
    LCD_Writ_Bus(dat);
    LCD_DC_Set();  //write data
}

void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
    if(USE_HORIZONTAL==0 || USE_HORIZONTAL==1)
    {
        LCD_WR_REG(0x2a);
        LCD_WR_DATA(x1);
        LCD_WR_DATA(x2);
        LCD_WR_REG(0x2b);
        LCD_WR_DATA(y1 + 20);
        LCD_WR_DATA(y2 + 20);
        LCD_WR_REG(0x2c);
    }
    else
    {
        LCD_WR_REG(0x2a);
        LCD_WR_DATA(x1 + 20);
        LCD_WR_DATA(x2 + 20);
        LCD_WR_REG(0x2b);
        LCD_WR_DATA(y1);
        LCD_WR_DATA(y2);
        LCD_WR_REG(0x2c);
    }
}

void LCD_Init(void)
{
    LCD_GPIO_Init();

    LCD_RES_Set();
    vTaskDelay(10/portTICK_PERIOD_MS);
    LCD_RES_Clr();
    vTaskDelay(10/portTICK_PERIOD_MS);
    LCD_RES_Set();
    vTaskDelay(120/portTICK_PERIOD_MS);

    LCD_BLK_Set();

    LCD_WR_REG(0xfd);     //private_access
    LCD_WR_DATA8(0x06);
    LCD_WR_DATA8(0x08);

    LCD_WR_REG(0x61);
    LCD_WR_DATA8(0x07);
    LCD_WR_DATA8(0x04);

    LCD_WR_REG(0x62);//bias setting
	LCD_WR_DATA8(0x00);//00
	LCD_WR_DATA8(0x44);//44
	LCD_WR_DATA8(0x45);//40  47

	LCD_WR_REG(0x63);//
	LCD_WR_DATA8(0x41);//
	LCD_WR_DATA8(0x07);//
	LCD_WR_DATA8(0x12);//
	LCD_WR_DATA8(0x12);//

	LCD_WR_REG(0x64);//
	LCD_WR_DATA8(0x37);//
	//VSP
	LCD_WR_REG(0x65);//Pump1=4.7MHz //PUMP1 VSP
	LCD_WR_DATA8(0x09);//D6-5:pump1_clk[1:0] clamp 28 2b
	LCD_WR_DATA8(0x10);//6.26
	LCD_WR_DATA8(0x21);
	//VSN
	LCD_WR_REG(0x66); //pump=2 AVCL
	LCD_WR_DATA8(0x09); //clamp 08 0b 09
	LCD_WR_DATA8(0x10); //10
	LCD_WR_DATA8(0x21);
	//add source_neg_time
	LCD_WR_REG(0x67);//pump_sel
	LCD_WR_DATA8(0x20);//21 20
	LCD_WR_DATA8(0x40);

	//gamma vap/van
	LCD_WR_REG(0x68);//gamma vap/van
	LCD_WR_DATA8(0x90);//
	LCD_WR_DATA8(0x4c);//
	LCD_WR_DATA8(0x7C);//VCOM  
	LCD_WR_DATA8(0x66);//

	LCD_WR_REG(0xb1);//frame rate
	LCD_WR_DATA8(0x0F);//0x0f fr_h[5:0] 0F
	LCD_WR_DATA8(0x02);//0x02 fr_v[4:0] 02
	LCD_WR_DATA8(0x01);//0x04 fr_div[2:0] 04

	LCD_WR_REG(0xB4);
	LCD_WR_DATA8(0x01); //01:1dot 00:column
	////porch
	LCD_WR_REG(0xB5);
	LCD_WR_DATA8(0x02);//0x02 vfp[6:0]
	LCD_WR_DATA8(0x02);//0x02 vbp[6:0]
	LCD_WR_DATA8(0x0a);//0x0A hfp[6:0]
	LCD_WR_DATA8(0x14);//0x14 hbp[6:0]

	LCD_WR_REG(0xB6);
	LCD_WR_DATA8(0x04);//
	LCD_WR_DATA8(0x01);//
	LCD_WR_DATA8(0x9f);//
	LCD_WR_DATA8(0x00);//
	LCD_WR_DATA8(0x02);//
	////gamme sel
	LCD_WR_REG(0xdf);//
	LCD_WR_DATA8(0x11);//gofc_gamma_en_sel=1
	////gamma_test1 A1#_wangly
	//3030b_gamma_new_
	//GAMMA---------------------------------/////////////

	//GAMMA---------------------------------/////////////
	LCD_WR_REG(0xE2);	
	LCD_WR_DATA8(0x13);//vrp0[5:0]	V0 13
	LCD_WR_DATA8(0x00);//vrp1[5:0]	V1 
	LCD_WR_DATA8(0x00);//vrp2[5:0]	V2 
	LCD_WR_DATA8(0x30);//vrp3[5:0]	V61 
	LCD_WR_DATA8(0x33);//vrp4[5:0]	V62 
	LCD_WR_DATA8(0x3f);//vrp5[5:0]	V63

	LCD_WR_REG(0xE5);	
	LCD_WR_DATA8(0x3f);//vrn0[5:0]	V63
	LCD_WR_DATA8(0x33);//vrn1[5:0]	V62	
	LCD_WR_DATA8(0x30);//vrn2[5:0]	V61 
	LCD_WR_DATA8(0x00);//vrn3[5:0]	V2 
	LCD_WR_DATA8(0x00);//vrn4[5:0]	V1 
	LCD_WR_DATA8(0x13);//vrn5[5:0]  V0 13

	LCD_WR_REG(0xE1);	
	LCD_WR_DATA8(0x00);//prp0[6:0]	V15
	LCD_WR_DATA8(0x57);//prp1[6:0]	V51 

	LCD_WR_REG(0xE4);	
	LCD_WR_DATA8(0x58);//prn0[6:0]	V51 
	LCD_WR_DATA8(0x00);//prn1[6:0]  V15

	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0x01);//pkp0[4:0]	V3 
	LCD_WR_DATA8(0x03);//pkp1[4:0]	V7  
	LCD_WR_DATA8(0x0d);//pkp2[4:0]	V21
	LCD_WR_DATA8(0x0e);//pkp3[4:0]	V29 
	LCD_WR_DATA8(0x0e);//pkp4[4:0]	V37 
	LCD_WR_DATA8(0x0c);//pkp5[4:0]	V45 
	LCD_WR_DATA8(0x15);//pkp6[4:0]	V56 
	LCD_WR_DATA8(0x19);//pkp7[4:0]	V60 

	LCD_WR_REG(0xE3);	
	LCD_WR_DATA8(0x1a);//pkn0[4:0]	V60 
	LCD_WR_DATA8(0x16);//pkn1[4:0]	V56 
	LCD_WR_DATA8(0x0C);//pkn2[4:0]	V45 
	LCD_WR_DATA8(0x0f);//pkn3[4:0]	V37 
	LCD_WR_DATA8(0x0e);//pkn4[4:0]	V29 
	LCD_WR_DATA8(0x0d);//pkn5[4:0]	V21 
	LCD_WR_DATA8(0x02);//pkn6[4:0]	V7  
	LCD_WR_DATA8(0x01);//pkn7[4:0]	V3 
	//GAMMA---------------------------------/////////////

	//source
	LCD_WR_REG(0xE6);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0xff);//SC_EN_START[7:0] f0

	LCD_WR_REG(0xE7);
	LCD_WR_DATA8(0x01);//CS_START[3:0] 01
	LCD_WR_DATA8(0x04);//scdt_inv_sel cs_vp_en
	LCD_WR_DATA8(0x03);//CS1_WIDTH[7:0] 12
	LCD_WR_DATA8(0x03);//CS2_WIDTH[7:0] 12
	LCD_WR_DATA8(0x00);//PREC_START[7:0] 06
	LCD_WR_DATA8(0x12);//PREC_WIDTH[7:0] 12

	LCD_WR_REG(0xE8); //source
	LCD_WR_DATA8(0x00); //VCMP_OUT_EN 81-
	LCD_WR_DATA8(0x70); //chopper_sel[6:4]
	LCD_WR_DATA8(0x00); //gchopper_sel[6:4] 60
	////gate
	LCD_WR_REG(0xEc);
	LCD_WR_DATA8(0x52);//52

	LCD_WR_REG(0xF1);
	LCD_WR_DATA8(0x01);//te_pol tem_extend 00 01 03
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x02);


	LCD_WR_REG(0xF6);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x00);//
	LCD_WR_DATA8(0x00);//40 3线2通道

	LCD_WR_REG(0xfd);
	LCD_WR_DATA8(0xfa);
	LCD_WR_DATA8(0xfc);

	LCD_WR_REG(0x3a);
	LCD_WR_DATA8(0x05);//

	LCD_WR_REG(0x35);
	LCD_WR_DATA8(0x00);

	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x08);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC8);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x78);
	else LCD_WR_DATA8(0xA8);


	LCD_WR_REG(0x21); 

    LCD_WR_REG(0x11);
    vTaskDelay(200/portTICK_PERIOD_MS);
    LCD_WR_REG(0x29);
    vTaskDelay(10/portTICK_PERIOD_MS);

    ESP_LOGI(TAG,"lcd init finish");
}

void EnterSleep(void)
{
	LCD_WR_REG(0x28);
	LCD_WR_REG(0x10);
	vTaskDelay(120/portTICK_PERIOD_MS);
}

void ExitSleep(void)
{
	LCD_WR_REG(0x11);
	vTaskDelay(120/portTICK_PERIOD_MS);
	LCD_WR_REG(0x29);
	vTaskDelay(10/portTICK_PERIOD_MS);
}

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color)
{          
	uint16_t i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}