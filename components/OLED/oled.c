#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"
#include "delay.h"
#include <string.h>
#include <math.h>

#define OLED_WIDTH  128
#define OLED_HEIGHT 8

u8 OLED_GRAM[224][8];
u8 ROWS = 48;
u8 COLS = 3;

const char *font_init[]={
	"wheel",
	"Yaw",
	"Pitch",
	"X-ray"
};

u8 strlen1(u8 *str)
{
    u8 count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//反显函数
void OLED_ColorTurn(u8 i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xA6,OLED_CMD);//正常显示
		}
	if(i==1)
		{
			OLED_WR_Byte(0xA7,OLED_CMD);//反色显示
		}
}

//??????180??
void OLED_DisplayTurn(u8 i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xC8,OLED_CMD);//正常显示
			OLED_WR_Byte(0xA1,OLED_CMD);
		}
	if(i==1)
		{
			OLED_WR_Byte(0xC0,OLED_CMD);//反转显示
			OLED_WR_Byte(0xA0,OLED_CMD);
		}
}

//延时
void IIC_delay(void)
{
	u8 t=3;
	while(t--);
}

//起始信号
void I2C_Start(void)
{
	OLED_SDA_Set();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Clr();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//结束信号
void I2C_Stop(void)
{
	OLED_SDA_Clr();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Set();
}

//等待信号响应
void I2C_WaitAck(void)  //测数据信号的电平
{
	OLED_SDA_Set();
	IIC_delay();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//写入一个字节
void Send_Byte(u8 dat)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		if(dat&0x80)//将dat的8位从最高位依次写入
		{
			OLED_SDA_Set();
    }
		else
		{
			OLED_SDA_Clr();
    }
		IIC_delay();
		OLED_SCL_Set();
		IIC_delay();
		OLED_SCL_Clr();//将时钟信号设置为低电平
		dat<<=1;
  }
}


//发送一个字节
//mode:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 mode)
{
	I2C_Start();
	Send_Byte(0x78);
	I2C_WaitAck();
	if(mode){Send_Byte(0x40);}
  else{Send_Byte(0x00);}
	I2C_WaitAck();
	Send_Byte(dat);
	I2C_WaitAck();
	I2C_Stop();
}

//开启OLED显示 
void OLED_DisPlay_On(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);//电荷泵使能
	OLED_WR_Byte(0x14,OLED_CMD);//开启电荷泵
	OLED_WR_Byte(0xAF,OLED_CMD);//点亮屏幕
}

//关闭OLED显示 
void OLED_DisPlay_Off(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);//???????
	OLED_WR_Byte(0x10,OLED_CMD);//??????
	OLED_WR_Byte(0xAE,OLED_CMD);//??????
}

void OLED_Set_Pos(u8 x,u8 y)
{
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte((x & 0x0F),OLED_CMD);
	OLED_WR_Byte(((x & 0xF0)>>4) | 0x10,OLED_CMD);
}

void OLEDon(void)
{
	u8 x,y;
	for(y=0;y<8;y++)
	{
		
		for(x=0;x<128;x++)
		{
			OLED_Set_Pos(x,y);
			OLED_WR_Byte(0xFF,OLED_CMD);
		}
	}

	
}


//更新显存到OLED	
void OLED_Refresh(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte(0xb0+i,OLED_CMD);//设置行起始地址
		OLED_WR_Byte(0x02,OLED_CMD);   //设置低列起始地址
		OLED_WR_Byte(0x10,OLED_CMD);  //设置高列起始地址
		I2C_Start();
		Send_Byte(0x78);
		I2C_WaitAck();
		Send_Byte(0x40);
		I2C_WaitAck();
		for(n=49;n<176;n++)
		{
			Send_Byte(OLED_GRAM[n][i]);
			I2C_WaitAck();
		}
		I2C_Stop();
  }
}

void OLED_Refresh1(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte(0xb0+i,OLED_CMD);//设置行起始地址
		OLED_WR_Byte(0x02,OLED_CMD);   //设置低列起始地址
		OLED_WR_Byte(0x10,OLED_CMD);  //设置高列起始地址
		I2C_Start();
		Send_Byte(0x78);
		I2C_WaitAck();
		Send_Byte(0x40);
		I2C_WaitAck();
		for(n=49;n<176;n++)
		{
			Send_Byte(OLED_GRAM[n][i]);
			I2C_WaitAck();
		}
		I2C_Stop();
  }
}

//清屏函数
void OLED_Clear(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
	   for(n=0;n<128;n++)
			{
			 OLED_GRAM[n][i]=0;//???????????
			}
  }
	OLED_Refresh();//???????
}

void AOLED_Clear(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
	{
	   for(n=45;n<128;n++)
			{
			 OLED_GRAM[n][i]=0;//???????????
			}
  }

}

//???? 
//x:0~127
//y:0~63
//t:1 ??? 0,???	
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 i,m,n;
	i=y/8;
	m=y%8;
	n=1<<m;
	if(t){OLED_GRAM[x][i]|=n;}
	else
	{
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
		OLED_GRAM[x][i]|=n;
		OLED_GRAM[x][i]=~OLED_GRAM[x][i];
	}
}



//????
//x1,y1:???????
//x2,y2:????????
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //???????????? 
	delta_y=y2-y1;
	uRow=x1;//???????????
	uCol=y1;
	if(delta_x>0)incx=1; //??????????? 
	else if (delta_x==0)incx=0;//????? 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//???? 
	else {incy=-1;delta_y=-delta_x;}
	if(delta_x>delta_y)distance=delta_x; //???????????????? 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		OLED_DrawPoint(uRow,uCol,mode);//????
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
//x,y:???????
//r:????
void  OLED_DrawCircle(u8 x,u8 y,u8 r)
{
	int a, b,num;
    a = 0;
    b = r;
    while(2 * b * b >= r * r)      
    {
        OLED_DrawPoint(x + a, y - b,1);
        OLED_DrawPoint(x - a, y - b,1);
        OLED_DrawPoint(x - a, y + b,1);
        OLED_DrawPoint(x + a, y + b,1);
 
        OLED_DrawPoint(x + b, y + a,1);
        OLED_DrawPoint(x + b, y - a,1);
        OLED_DrawPoint(x - b, y - a,1);
        OLED_DrawPoint(x - b, y + a,1);
        
        a++;
        num = (a * a + b * b) - r*r;//????????????????
        if(num > 0)
        {
            b--;
            a--;
        }
    }
}

void fullcircle(u8 x,u8 y,u8 r)
{
	u8 x0 = 0;
	u8 y0 = r;
	while(x0<=y)
	{
		OLED_DrawPoint(x + x0, y + y0,1);
		OLED_DrawPoint(x - x0, y + y0,1);
		OLED_DrawPoint(x - x0, y - y0,1);
		OLED_DrawPoint(x + x0, y - y0,1);
		OLED_DrawPoint(x + y0, y + x0,1);
		OLED_DrawPoint(x - y0, y + x0,1);
		OLED_DrawPoint(x - y0, y - x0,1);
		OLED_DrawPoint(x + y0, y - x0,1);
		x0++;
		if((x0*x0+y0*y0)>(r*r))
		{
			y0--;
		}
	}
	
	
}

void leftcircle(u8 x,u8 y,u8 r,u8 mode)
{

	int a, b,num;
    a = 0;
    b = r;
    while(2 * b * b >= r * r)      
    {

        OLED_DrawPoint(x - b, y - a,mode);
        OLED_DrawPoint(x - b, y + a,mode);
        a++;
        num = (a * a + b * b) - r*r;//????????????????
        if(num > 0)
        {
            b--;
            a--;
        }
    }
	
	

}

void rightcircle(u8 x,u8 y,u8 r,u8 mode)
{
	int a, b,num;
    a = 0;
    b = r;
    while(2 * b * b >= r * r)      
    {
        OLED_DrawPoint(x + b, y + a,mode);
        OLED_DrawPoint(x + b, y - a,mode);
     
        a++;
        num = (a * a + b * b) - r*r;//????????????????
        if(num > 0)
        {
            b--;
            a--;
        }
    }
}

void circle()
{
	OLED_DrawLine(3,0,6+strlen1((u8 *)font_init[0])*6,0,1);
	OLED_DrawLine(3,15,6+strlen1((u8 *)font_init[0])*6,15,1);
	rightcircle(27,8,12,1);
	leftcircle(12,8,12,1);

}



//??????????????????,???????????
//x:0~127
//y:0~63
//size1:??????? 6x8/6x12/8x16/12x24
//mode:0,??????;1,???????
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode)
{
	u8 i,m,temp,size2,chr1;
	u8 x0=x,y0=y;
	if(size1==8)size2=6;
	else size2=(size1/8+((size1%8)?1:0))*(size1/2);  //??????????????????????????????
	chr1=chr-' ';  //??????????
	for(i=0;i<size2;i++)
	{
		if(size1==8)
			  {temp=asc2_0806[chr1][i];} //????0806????
		else if(size1==12)
        {temp=asc2_1206[chr1][i];} //????1206????
		else if(size1==16)
        {temp=asc2_1608[chr1][i];} //????1608????
		else if(size1==24)
        {temp=asc2_2412[chr1][i];} //????2412????
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((size1!=8)&&((x-x0)==size1/2))
		{x=x0;y0=y0+8;}
		y=y0;
  }
}


//????????
//x,y:???????  
//size1:??????? 
//*chr:??????????? 
//mode:0,??????;1,???????
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode)
{
	while((*chr>=' ')&&(*chr<='~'))//??????????????!
	{
		OLED_ShowChar(x,y,*chr,size1,mode);
		if(size1==8)x+=6;
		else x+=size1/2;
		chr++;
  }
}

//m^n
u32 OLED_Pow(u8 m,u8 n)
{
	u32 result=1;
	while(n--)
	{
	  result*=m;
	}
	return result;
}

//???????
//x,y :???????
//num :??????????
//len :?????????
//size:???????
//mode:0,??????;1,???????
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode)
{
	u8 t,temp,m=0;
	if(size1==8)m=2;
	for(t=0;t<len;t++)
	{
		temp=(num/OLED_Pow(10,len-t-1))%10;
			if(temp==0)
			{
				OLED_ShowChar(x+(size1/2+m)*t,y,'0',size1,mode);
      }
			else 
			{
			  OLED_ShowChar(x+(size1/2+m)*t,y,temp+'0',size1,mode);
			}
  }
}

//???????
//x,y:???????
//num:???????????
//mode:0,??????;1,???????
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode)
{
	u8 m,temp;
	u8 x0=x,y0=y;
	u16 i,size3=(size1/8+((size1%8)?1:0))*size1;  //??????????????????????????????
	for(i=0;i<size3;i++)
	{
		if(size1==16)
				{temp=no_cut[num][i];}//????16*16????
		else if(size1==12)
				{temp=moca[num][i];}//12*12
		else if(size1==32)       
				{temp=Hzk3[num][i];}//????32*32????
		else if(size1==64)
				{temp=Hzk4[num][i];}//????64*64????
		else return;
		for(m=0;m<8;m++)
		{
			if(temp&0x01)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp>>=1;
			y++;
		}
		x++;
		if((x-x0)==size1)
		{x=x0;y0=y0+8;}
		y=y0;
	}
}

//num ???????????
//space ???????????
//mode:0,??????;1,???????
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode)
{
	u8 i,n,t=0,m=0,r;
	while(1)
	{
		if(m==0)
		{
	    OLED_ShowChinese(128,24,t,16,mode); //????????????????OLED_GRAM[][]??????
			t++;
		}
		if(t==num)
			{
				for(r=0;r<16*space;r++)      //??????
				 {
					for(i=1;i<144;i++)
						{
							for(n=0;n<8;n++)
							{
								OLED_GRAM[i-1][n]=OLED_GRAM[i][n];
							}
						}
           OLED_Refresh();
				 }
			t=0;
			}
		m++;
		if(m==16){m=0;}
		for(i=1;i<224;i++)   //???????
		{
			for(n=0;n<8;n++)
			{
				OLED_GRAM[i-1][n]=OLED_GRAM[i][n];
			}
		}
		OLED_Refresh();	
	}
}



void OLED_ScrollDisplayL()
{
	u8 i,n;
		
			for(u8 j =0;j<87;j++)
			{
				
				for(i=1;i<224;i++)   
				{
					for(n=0;n<8;n++)
					{
						OLED_GRAM[i-1][n]=OLED_GRAM[i][n];
					}
				}
				if(j==0 || j==1 || j==2 || j==3 || j==4 || j==5 || j==6 || j==7 || j==14 ||j==13 ||j==42|| j==43 || j==44 || j==73	 || j==72 || j==80 || j==81 || j==82 || j==83 || j==85 || j==84 || j==86 ||j==87)
				{
					OLED_Refresh();
				}
			}
			
}

void OLED_ScrollDisplayR()
{
	u8 i,n;
		
			for(u8 j =0;j<87;j++)
			{
				
				for(i=224;i>0;i--)   //???????
				{
					for(n=0;n<8;n++)
					{
						OLED_GRAM[i][n]=OLED_GRAM[i-1][n];
					}
				}
				if(j==0 || j==1 || j==2 || j==3 || j==4 || j==5 || j==6 || j==7 || j==8 ||j==13 ||j==42|| j==43 || j==44 || j==73	 || j==79 || j==80 || j==81 || j==82 || j==83 || j==85 || j==84 || j==86 ||j==87)
				{
					OLED_Refresh1();
				}
			}
			
}


float M_PI = 3.1415926;



u8 bilinearInterpolation(u8 tl, u8 tr, u8 bl, u8 br, double x_ratio, double y_ratio) {
    return (u8)((tl * (1 - x_ratio) * (1 - y_ratio)) +
                     (tr * x_ratio * (1 - y_ratio)) +
                     (bl * y_ratio * (1 - x_ratio)) +
                     (br * x_ratio * y_ratio));
}

void rotateOLEDArbitrary(double angle) {

    double radians = angle * M_PI / 180.0;


    u8 newWidth = ceil(fabs(OLED_WIDTH * cos(radians)) + fabs(OLED_HEIGHT * sin(radians)));
    u8 newHeight = ceil(fabs(OLED_WIDTH * sin(radians)) + fabs(OLED_HEIGHT * cos(radians)));


    u8 rotatedBuffer[newWidth][newHeight];

    double cx = OLED_WIDTH / 2.0;
    double cy = OLED_HEIGHT / 2.0;

     for (int x = 0; x < newWidth; x++) {
        for (int y = 0; y < OLED_HEIGHT; y++) {
            // ???????
            double xo = cos(radians) * (x - cx) + sin(radians) * (y - cy) + cx;
            double yo = -sin(radians) * (x - cx) + cos(radians) * (y - cy) + cy;

            // ??????????,?????
            if (xo >= 0 && xo < OLED_WIDTH) {
                int x0 = floor(xo);
                int y0 = y;
                int x1 = x0 + 1;
                int y1 = y0 + 1;

                // ????
                if (x1 >= OLED_WIDTH) x1 = OLED_WIDTH - 1;

                // ???????
                rotatedBuffer[y][x] = bilinearInterpolation(
                    OLED_GRAM[y0][x0],
                    OLED_GRAM[y0][x1],
                    OLED_GRAM[y1][x0],
                    OLED_GRAM[y1][x1],
                    xo - x0,
                    yo - y0
                );
            } else {
                // ??????????,????????????
                rotatedBuffer[y][x] = 0; // ??????
            }
        }
    }


				for(u8 i=1;i<176;i++)   
				{
					for(u8 n=0;n<8;n++)
					{
						OLED_GRAM[i][n] = rotatedBuffer[i][n];
					}
				}
//				if(j==0 || j==1 || j==2 || j==3 || j==4 || j==5 || j==6 || j==7 || j==14 ||j==13 ||j==42|| j==43 || j==44 || j==73	 || j==72 || j==80 || j==81 || j==82 || j==83 || j==85 || j==84 || j==86 ||j==87)
//				{
					OLED_Refresh();
//				}
			}



//void rotateImage(u8 OLED_GRAM[ROWS][COLS], u8 centerx, u8 centery, float angle) {

//    float beta = angle * M_PI / 180.0;
//    
//    for (int y0 = 0; y0 < ROWS; y0++) {
//        for (int x0 = 0; x0 < COLS; x0++) {

//            int x = (x0 - centerx) * cos(beta) - (y0 - centery) * sin(beta) + centerx;
//            int y = (x0 - centerx) * sin(beta) + (y0 - centery) * cos(beta) + centery;

//            if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
//                OLED_GRAM[y][x] = OLED_GRAM[y0][x0];
//								OLED_Refresh1();
//            }
//        }
//    }
//}




void right(u8 a) {
	u8 i, n, r=0;
   while(r<a)
   {
		for (i = 144; i > 0; i--) 
		{
			for (n = 0; n < 8; n++) {
				OLED_GRAM[i][n]=OLED_GRAM[i-1][n];
			}
		}
	OLED_Refresh();
	r++;
   }
}


static u8 y1 = 12;
static u8 a = 0;
u8 move[4]={3,5,5,3};

void up1(void)
{
	OLED_DrawLine(3,y1+16,6+strlen1((u8 *)font_init[a])*6,4+y1+16,0);
	OLED_DrawLine(3,19+y1+16,6+strlen1((u8 *)font_init[a])*6,19+y1+16,0);
	rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1+16,12,0);
	leftcircle(12,12+y1-16,12,0);
	
	if(a==0)
	{
		a=3;
	}
	else{a--;}
	y1-=16;
	if(y1==-4)
	{
		y1 = 44;
	}
	OLED_DrawLine(3,4+y1,6+strlen1((u8 *)font_init[a])*6,4+y1,1);
	OLED_DrawLine(3,19+y1,6+strlen1((u8 *)font_init[a])*6,19+y1,1);
	rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1,12,1);
	leftcircle(12,12+y1,12,1);
	
	
	

	
	
	
	
	
	
}

void down(void) 
{
	u8 i,j=0;
	for(i=0;i<4;i++)
	{
		OLED_DrawLine(3,4+y1-16,6+strlen1((u8 *)font_init[a])*6,4+y1-16,0);
		OLED_DrawLine(3,19+y1-16,6+strlen1((u8 *)font_init[a])*6,19+y1-16,0);
		rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1-16,12,0);
		leftcircle(12,12+y1-16,12,0);
		if(j==0)
		{
			a++;
		}
		
		if(y1==76)
		{
			y1 = 12;
		}
		if(a==4)
		{
			a=0;
		}
		
		OLED_DrawLine(3,4+y1,6+strlen1((u8 *)font_init[a])*6,4+y1,1);
		OLED_DrawLine(3,19+y1,6+strlen1((u8 *)font_init[a])*6,19+y1,1);
		rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1,12,1);
		leftcircle(12,12+y1,12,1);
		// OLED_ShowString(6,1,(u8 *)font_init[a-1],12,1);
		// OLED_ShowString(6,1,(u8 *)font_init[a],12,1);
		OLED_Refresh();
		y1+=move[i];
	}
}

void down1(void) 
{
	OLED_DrawLine(3,4+y1-16,6+strlen1((u8 *)font_init[a])*6,4+y1-16,0);
	OLED_DrawLine(3,19+y1-16,6+strlen1((u8 *)font_init[a])*6,19+y1-16,0);
	rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1-16,12,0);
	leftcircle(12,12+y1-16,12,0);
	a++;
	if(y1==76)
	{
		y1 = 12;
	}
	if(a==4)
	{
		a=0;
	}

	switch (a)
	{
		case 0:
		{
			AOLED_Clear();
			OLED_ShowString(45,1,"1:",12,1);
			OLED_ShowString(45,17,"2:",12,1);
			OLED_ShowString(45,33,"3:",12,1);
			OLED_ShowString(45,49,"4:",12,1);
			break;
		}
		case 1:
		{
			AOLED_Clear();
			break;
		}	
		case 2:
		{
			AOLED_Clear();
			break;
		}
		case 3:
		{
			AOLED_Clear();
			break;
		}
	}
	
	OLED_DrawLine(3,4+y1,6+strlen1((u8 *)font_init[a])*6,4+y1,1);
	OLED_DrawLine(3,19+y1,6+strlen1((u8 *)font_init[a])*6,19+y1,1);
	rightcircle(strlen1((u8 *)font_init[a])*6-3,12+y1,12,1);
	leftcircle(12,12+y1,12,1);
	y1+=16;
	
	
}



void gun(void)
{
	OLED_WR_Byte(0x2E,OLED_CMD);        //??????
  	OLED_WR_Byte(0x26,OLED_CMD);        //?????????????? 26/27
  	OLED_WR_Byte(0x00,OLED_CMD);        //???????
	OLED_WR_Byte(0x01,OLED_CMD);        //???? 0
	OLED_WR_Byte(0x07,OLED_CMD);        //?????????
	OLED_WR_Byte(0x07,OLED_CMD);        //???? 7
	OLED_WR_Byte(0x00,OLED_CMD);        //???????
	OLED_WR_Byte(0xFF,OLED_CMD);        //???????

	OLED_ShowChinese(6,0,0,12,1);
	OLED_ShowChinese(18,8,1,12,1);
	OLED_ShowChinese(30,8,2,12,1);

	OLED_WR_Byte(0x2F,OLED_CMD);        //????????

}

// void Scroll_down()
// {
// 	u8 i,n;
// 		for(n=0;n<8;n++)
// 		{
// 			for(i=1;i<144;i++)
// 			{
// 				OLED_GRAM[i][n-1]=OLED_GRAM[i][n];
				
// 			}
// 			OLED_Refresh();
// 		}
// }


//x,y?????????
//sizex,sizey,??????
//BMP[]??????????????
//mode:0,??????;1,???????
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode)
{
	u16 j=0;
	u8 i,n,temp,m;
	u8 x0=x,y0=y;
	sizey=sizey/8+((sizey%8)?1:0);
	for(n=0;n<sizey;n++)
	{
		 for(i=0;i<sizex;i++)
		 {
				temp=BMP[j];
				j++;
				for(m=0;m<8;m++)
				{
					if(temp&0x01)OLED_DrawPoint(x,y,mode);
					else OLED_DrawPoint(x,y,!mode);
					temp>>=1;
					y++;
				}
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y0=y0+8;
				}
				y=y0;
     }
	 }
}
//OLED??????
void OLED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //???A??????
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 		 //???????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//???50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //?????PA0,1
 	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //???????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//???50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //?????PA2
 	GPIO_SetBits(GPIOA,GPIO_Pin_2);



	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//???50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //?????PA0,1
 	GPIO_SetBits(GPIOA,GPIO_Pin_3);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//???50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //?????PA0,1
 	GPIO_SetBits(GPIOA,GPIO_Pin_4);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//???50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //?????PA0,1
 	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	
	OLED_RES_Clr();
	delay_ms(200);
	OLED_RES_Set();
	
	OLED_WR_Byte(0xAE,OLED_CMD);//--turn off oled panel ???OLED???
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address ??????????
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address ??????????
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)  ??????????????????RAM????????(0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);//--set contrast control register  ??????????????
	OLED_WR_Byte(0xCF,OLED_CMD);// Set SEG Output Current Brightness  ????SEG???????????
	OLED_WR_Byte(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0??????? 0xa1????
	OLED_WR_Byte(0xC8,OLED_CMD);//Set COM/Row Scan Direction   0xc0???????? 0xc8????
	OLED_WR_Byte(0xA6,OLED_CMD);//--set normal display  ???????????
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)  ?????????????(1??64)
	OLED_WR_Byte(0x3f,OLED_CMD);//--1/64 duty  
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)  ?????????????????RAM??????(0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);//-not offset
	OLED_WR_Byte(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency  ??????????????/???????
	OLED_WR_Byte(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec  ??????????????????100?/??
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period  ??????????
	OLED_WR_Byte(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock  ???????????15????????????????1?????
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration  ????COM???????????
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0x20,OLED_CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02,OLED_CMD);//
	OLED_WR_Byte(0x8D,OLED_CMD);//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);//--set(0x10) disable
	OLED_WR_Byte(0xA4,OLED_CMD);// Disable Entire Display On (0xa4/0xa5)  ?????????????(0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);// Disable Inverse Display On (0xa6/a7)  ????????????(0xa6/A7)
	//OLED_Clear();
	OLED_WR_Byte(0xAF,OLED_CMD);
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  	OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
	OLED_Clear();

	
}

void Menu_Init(void)
{

	OLED_ShowString(6,1,(u8 *)font_init[0],12,1);
	OLED_ShowString(6,17,(u8 *)font_init[1],12,1);
	OLED_ShowString(6,33,(u8 *)font_init[2],12,1);
	OLED_ShowString(6,49,(u8 *)font_init[3],12,1);
	OLED_ShowString(45,1,"1:",12,1);
	OLED_ShowString(45,17,"2:",12,1);
	OLED_ShowString(45,33,"3:",12,1);
	OLED_ShowString(45,49,"4:",12,1);
	circle();

	OLED_Refresh();

}


