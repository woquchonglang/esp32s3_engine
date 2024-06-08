#ifndef __BMP_H
#define __BMP_H

static unsigned char bmp_dart[] =
{
0xFE,0xFD,0xF1,0xE3,0xC7,0x87,0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xFE,0x1F,0x0F,0x03,0x03,0x01,0x01,0x01,
0x01,0x01,0x01,0x03,0x03,0x0F,0x0F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x1F,0x7F,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,
0xFE,0xFC,0xF8,0xF0,0xF0,0xE0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x81,0xC7,0xEF,0xFF,0x7F,0x7F,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xFC,0xFC,0x9E,0x1F,
0x0F,0x13,0x33,0x61,0x82,0x86,0x0C,0x30,0x70,0xF0,0xF0,0xE0,0xE0,0xE1,0xC1,0xC3,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,
0xE0,0xC0,0x80,0x00,0x03,0x1F,0xFF,0xFE,0xFC,0xFC,0xFB,0xF7,0xFF,0xFF,0xFF,0xFF,/*"D:\??\WhhDart.bmp",0*/

};

unsigned char bmp_tem[] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x87,0x87,0xC7,0xC7,0xC7,0x87,
0x87,0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0xFF,0x0F,0x07,0x07,0x07,0x07,0x0F,0xFF,0xFF,
0xFF,0x7F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFE,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,
0xFF,0x00,0x00,0x00,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x03,0x03,0x03,0xFF,
0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x00,0x80,0xE0,0xFF,0x7F,0x3F,0x00,0x00,0x00,0x3F,
0x7F,0xFF,0xE0,0xC0,0x00,0x0F,0x0F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFC,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x80,0x00,0x00,0x1F,0x7F,0xFF,0xE0,0xC0,0x80,0x80,0x80,0x80,0x80,
0xC0,0xE0,0xFF,0x7F,0x1F,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xF8,0xF0,0xF0,0xE1,0xE3,0xE3,0xE3,0xE3,0xE3,
0xE1,0xF0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

};
unsigned char bmp_speed[] =
{

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x3F,
0x1F,0x1F,0x0F,0x0F,0x8F,0x8F,0x8F,0x0F,0x0F,0x0F,0x8F,0x8F,0x0F,0x0F,0x1F,0x1F,
0x3F,0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x1F,0x07,0x83,0xC1,0xC0,0x80,0x00,0x0C,0x1E,
0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF8,0xFF,0xFF,0xFF,0x7F,0x3E,0x1E,
0x1E,0x1C,0xF8,0xF0,0xE0,0xC1,0x83,0x07,0x0F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x00,0x40,0x7C,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x07,0x03,0x01,0x00,0x80,0xE0,0xF0,
0xFC,0xFF,0xFF,0xFF,0x7F,0x7F,0x7F,0x7C,0x70,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x3C,0xFC,0xFC,0xFC,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xF8,0xF0,0xE0,0xE0,0xE0,0xE0,0xF0,0xF8,0xFE,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFC,0xFC,0xFC,0x3C,0x0C,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xE0,0xC1,0x81,0x07,0x0F,0x1F,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0x1F,0x0F,0x07,0x83,0xC1,0xE0,0xF0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*"H:\engine\stm32\oled\images\FluentTopSpeed24Regular.bmp",0*/


};
unsigned char bmp_xyz[] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x7C,0x3C,0x0C,0x04,0x60,0x70,0x78,0x7C,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0x02,0x02,0x02,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,
0x3F,0x1F,0x0F,0x8F,0x87,0xC7,0xC3,0xE0,0xE0,0xE0,0xC7,0x87,0x8F,0x0F,0x1F,0x3F,
0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0x7F,0x7F,0x77,0xE3,0xE3,0xF1,0xF0,0xF8,0xFC,0xFC,
0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,
0xFC,0xFC,0xF8,0xF0,0xF1,0xE1,0xE3,0x77,0x7F,0x7F,0xFF,0xFF,0xFF,0x7F,0x7F,0x7F,
0x7F,0x3E,0x08,0xC0,0xE3,0x80,0x18,0x1C,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0x00,0x03,0x00,0xF8,0xFC,0xFF,

};
unsigned char bmp_laser[] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0x7F,0x3F,0x0F,0x03,0x03,0x0F,0x1F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xCF,0x0F,0x0F,0x0F,0x07,0x87,0xE7,0xF7,0xFF,0x7F,0x3F,
0x1F,0x1E,0x0E,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x0E,0x1E,0x1F,0x3F,0x7F,0xFF,0xF7,
0xE7,0x87,0x07,0x0F,0x0F,0x0F,0xCF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xFF,0xFF,0xFF,0x03,0x01,0x00,0x00,
0x60,0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFC,0xE0,0x00,0x00,0x00,0x03,
0xFF,0xFF,0xFF,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x0F,0x03,0x01,0x0F,0x1F,0x7F,0xFC,0xF8,0xE0,0xC0,
0xC0,0x81,0x87,0x07,0x0F,0x0F,0x0F,0x0F,0x07,0x87,0x83,0xC0,0xC0,0xE0,0xF8,0xFC,
0x3F,0x0F,0x03,0x03,0x03,0xC3,0xFF,0xFF,0xFF,0x3F,0x03,0x03,0x03,0x83,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC3,0xC3,0xC1,0xE1,0xE0,0xE0,
0xF0,0xF0,0x78,0x7C,0x3F,0x1F,0x0F,0x03,0x01,0x80,0xE0,0xF0,0xFC,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC3,0xC3,0xC3,0xC3,0xC1,0xE1,
0xE0,0xE0,0xF0,0xF0,0xF8,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

};
unsigned char bmp_loop[] =
{

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x3F,
0x1F,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1F,
0x3F,0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x1F,0x07,0x03,0x01,0xC0,0xE0,0xF0,0xF8,0xFC,
0xFC,0xFC,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0xFC,0xFC,
0x78,0x70,0x70,0x60,0x00,0x01,0x03,0x07,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0x00,0x00,0xE0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x07,0x00,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xE0,0xC0,0x80,0x02,0x06,0x0E,0x1E,0x1E,
0x3F,0x3F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x7F,0x3F,0x3F,
0x1F,0x1F,0x0F,0x07,0x03,0x81,0xC0,0xE0,0xF0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xFC,
0xF8,0xF8,0xF8,0xF8,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF8,0xF8,0xF8,0xF8,
0xFC,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

};
unsigned char bmp_goal[] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x7F,0x7F,0x7F,0x7F,0x3F,0x3F,0x03,0x07,0x07,0x3F,0x7F,0x7F,0x7F,0x7F,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x1F,0x0F,0x83,0x83,0xE1,0xF1,
0xF0,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xF0,
0xF1,0xE1,0xC3,0x83,0x0F,0x0F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x3F,0x3F,0x3F,0x1F,0x03,0x00,0x00,0xF0,0xFE,0xFF,0xFF,0xFF,0xFF,
0xFF,0x0F,0x07,0x03,0xC1,0xE1,0xF0,0xF0,0xF0,0xF0,0xE1,0xC1,0x03,0x07,0x0F,0x3F,
0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0x00,0x00,0x01,0x1F,0x3F,0x3F,0x3F,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xF8,0xC0,0x00,0x00,0x0F,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xF0,0xE0,0xC0,0x83,0x87,0x8F,0x8F,0x8F,0x8F,0x87,0x83,0xC0,0xE0,0xF0,0xFC,
0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x00,0x00,0x80,0xF8,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF8,0xF0,0xE1,0xC1,0x83,0x8F,
0x0F,0x1F,0x1F,0x1F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x1F,0x1F,0x1F,0x0F,
0x8F,0x83,0xC3,0xE1,0xF0,0xF0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFE,0xFE,0xFE,0xFC,0xFC,0xC0,0xE0,0xE0,0xFC,0xFE,0xFE,0xFE,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,

};


#endif

