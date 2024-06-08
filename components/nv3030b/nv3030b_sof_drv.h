/*
 * @Author: yjy 3253932102@qq.com
 * @Date: 2024-06-07 23:52:44
 * @LastEditors: yjy 3253932102@qq.com
 * @LastEditTime: 2024-06-08 19:59:37
 * @FilePath: /mpu6050/components/nv3030b/nv3030b_sof_drv.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "driver/gpio.h"


#ifndef NV3030B_SOF_DRV_H
#define NV3030B_SOF_DRV_H

#define USE_HORIZONTAL 1  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 280

#else
#define LCD_W 280
#define LCD_H 240
#endif

#define scl_sof_gpio 4
#define sda_sof_gpio 5
#define res_sof_gpio 6
#define dc_sof_gpio 7
#define cs_sof_gpio 15
#define blk_sof_gpio 16

//-----------------LCD端口定义---------------- 

#define LCD_SCLK_Clr() gpio_set_level(scl_sof_gpio,0)//SCL=SCLK
#define LCD_SCLK_Set() gpio_set_level(scl_sof_gpio,1)

#define LCD_MOSI_Clr() gpio_set_level(sda_sof_gpio,0)//SDA=MOSI
#define LCD_MOSI_Set() gpio_set_level(sda_sof_gpio,1)

#define LCD_RES_Clr()  gpio_set_level(res_sof_gpio,0)//RES
#define LCD_RES_Set()  gpio_set_level(res_sof_gpio,1)

#define LCD_DC_Clr()   gpio_set_level(dc_sof_gpio,0)//DC
#define LCD_DC_Set()   gpio_set_level(dc_sof_gpio,1)
 		     
#define LCD_CS_Clr()   gpio_set_level(cs_sof_gpio,0)//CS
#define LCD_CS_Set()   gpio_set_level(cs_sof_gpio,1)

#define LCD_BLK_Clr()  gpio_set_level(blk_sof_gpio,0)//BLK
#define LCD_BLK_Set()  gpio_set_level(blk_sof_gpio,1)

void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(uint8_t dat);//模拟SPI时序
void LCD_WR_DATA8(uint8_t dat);//写入一个字节
void LCD_WR_DATA(uint16_t dat);//写入两个字节
void LCD_WR_REG(uint16_t dat);//写入一个指令
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//设置坐标函数
void LCD_Init(void);//LCD初始化

void EnterSleep(void);
void ExitSleep(void);
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);//指定区域填充颜色

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

#endif