#ifndef __OLED_H
#define __OLED_H 

#include "sys.h"

#include "stdlib.h"	

//-----------------OLED�˿ڶ���---------------- 

#define OLED_SCL_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_0)//SCL
#define OLED_SCL_Set() GPIO_SetBits(GPIOA,GPIO_Pin_0)

#define OLED_SDA_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_1)//DIN
#define OLED_SDA_Set() GPIO_SetBits(GPIOA,GPIO_Pin_1)

#define OLED_RES_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_2)//RES
#define OLED_RES_Set() GPIO_SetBits(GPIOA,GPIO_Pin_2)


#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

extern u8 OLED_GRAM[224][8];

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);

void OLED_Set_Pos(u8 x,u8 y);
void OLEDon(void);
void OLED_Refresh(void);
void OLED_Refresh1(void);
void OLED_Refresh2(void);


void OLED_Clear(void);

void AOLED_Clear(void);

void OLED_DrawPoint(u8 x,u8 y,u8 t);

void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);

void fullcircle(u8 x,u8 y,u8 r);
void leftcircle(u8 x,u8 y,u8 r,u8 mode);
void rightcircle(u8 x,u8 y,u8 r,u8 mode);
void circle(void);

void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);

void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ScrollDisplay1(u8 k);
void OLED_ScrollDisplayL();
void OLED_ScrollDisplayR();

extern u8 ROWS;
extern u8 COLS;

u8 bilinearInterpolation(u8 tl, u8 tr, u8 bl, u8 br, double x_ratio, double y_ratio);
void rotateImage(u8 OLED_GRAM[ROWS][COLS], u8 centerx, u8 centery, float angle) ;

void rotateOLEDArbitrary(double angle);

void right(u8 a);

void up1(void);
void down(void); 
void down1(void);
// void Scroll_down();

void gun(void);

void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);
void Menu_Init(void);

#endif

