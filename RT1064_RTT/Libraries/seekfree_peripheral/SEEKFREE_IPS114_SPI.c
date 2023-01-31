/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		IPSҺ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.28
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-03-06
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SCL                 �鿴IPS114_SCL_PIN�궨�������     Ӳ��SPI���Ų��������л�
						SDA                 �鿴IPS114_SDA_PIN�궨�������     Ӳ��SPI���Ų��������л�
						RES                 �鿴IPS114_REST_PIN�궨�������    
						DC                  �鿴IPS114_DC_PIN�궨�������  
						CS                  �鿴IPS114_CS_PIN�궨�������      Ӳ��SPI���Ų��������л�
						
						��Դ����
						BL  3.3V��Դ������������ţ�Ҳ���Խ�PWM���������ȣ�
						VCC 3.3V��Դ
						GND ��Դ��
						���ֱ���135*240
					------------------------------------ 

 ********************************************************************************************************************/

#include "zf_spi.h"
#include "zf_gpio.h"
#include "zf_iomuxc.h"
#include "zf_systick.h"
#include "SEEKFREE_PRINTF.h"
#include "SEEKFREE_IPS114_SPI.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips114_writeIndex(uint8 dat)			//д����
{
    IPS114_DC(0);
    spi_mosi(IPS114_SPIN_PIN,IPS114_CS_PIN,&dat,&dat,1,1);

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips114_writeData(uint8 dat)			//д����
{
    IPS114_DC(1);
    spi_mosi(IPS114_SPIN_PIN,IPS114_CS_PIN,&dat,&dat,1,1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips114_writedata_16bit(uint16 dat)	//��Һ����дһ��16λ����
{
    uint8 dat1[2];
    dat1[0] = dat >> 8;
    dat1[1] = (uint8)dat;

    IPS114_DC(1);
    spi_mosi(IPS114_SPIN_PIN,IPS114_CS_PIN,dat1,dat1,2,1); 	//д������  ��λ��ǰ  ��λ�ں�
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      1.14�� IPSҺ����ʼ��
//  @return     void
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips114_init(void)
{
    spi_init(IPS114_SPIN_PIN, IPS114_SCL_PIN, IPS114_SDA_PIN, IPS114_SDA_IN_PIN, IPS114_CS_PIN, 0, 48*1000*1000);//Ӳ��SPI��ʼ��

    gpio_init(IPS114_BL_PIN,GPO,1,GPIO_PIN_CONFIG);
    gpio_init(IPS114_DC_PIN,GPO,0,GPIO_PIN_CONFIG);
    gpio_init(IPS114_REST_PIN,GPO,0,GPIO_PIN_CONFIG);

    IPS114_REST(0);
    systick_delay_ms(200);

    IPS114_REST(1);
    systick_delay_ms(100);
//    ips114_writeIndex(0x11);
//    ips114_writeIndex(0x36);
//
//    if      (IPS114_DISPLAY_DIR==0)    ips114_writeData(0x00);
//    else if (IPS114_DISPLAY_DIR==1)    ips114_writeData(0xC0);
//    else if (IPS114_DISPLAY_DIR==2)    ips114_writeData(0x70);
//    else                            ips114_writeData(0xA0);
//
//    ips114_writeIndex(0x3A);
//    ips114_writeData(0x05);
//    ips114_writeData(0x36);
//    ips114_writeIndex(0xB2);
//    ips114_writeData(0x05);
//    ips114_writeData(0x3C);
//    ips114_writeData(0x3C);
//
//    ips114_writeIndex(0xB7);
//    ips114_writeData(0x35);
//
//    ips114_writeIndex(0xBB);
//    ips114_writeData(0x35);
//
//    ips114_writeIndex(0xC0);
//    ips114_writeData(0x2C);
//
//    ips114_writeIndex(0xC2);
//    ips114_writeData(0x01);
//
//    ips114_writeIndex(0xC3);
//    ips114_writeData(0x13);
//
//    ips114_writeIndex(0xC4);
//    ips114_writeData(0x20);
//
//    ips114_writeIndex(0xC6);
//    ips114_writeData(0x0F);
//
//    ips114_writeIndex(0xD0);
//    ips114_writeData(0xA4);
//    ips114_writeData(0xA1);
//
//    ips114_writeData(0xD6);
//    ips114_writeData(0xA1);
//
//    ips114_writeIndex(0xE0);
//    ips114_writeData(0xF0);
//    ips114_writeData(0x00);
//    ips114_writeData(0x04);
//    ips114_writeData(0x04);
//    ips114_writeData(0x04);
//    ips114_writeData(0x05);
//    ips114_writeData(0x29);
//    ips114_writeData(0x33);
//    ips114_writeData(0x3E);
//    ips114_writeData(0x38);
//    ips114_writeData(0x12);
//    ips114_writeData(0x12);
//    ips114_writeData(0x28);
//    ips114_writeData(0x30);
//
//    ips114_writeIndex(0xE1);
//    ips114_writeData(0xF0);
//    ips114_writeData(0x07);
//    ips114_writeData(0x0A);
//    ips114_writeData(0x0D);
//    ips114_writeData(0x0B);
//    ips114_writeData(0x07);
//    ips114_writeData(0x28);
//    ips114_writeData(0x33);
//    ips114_writeData(0x3E);
//    ips114_writeData(0x36);
//    ips114_writeData(0x14);
//    ips114_writeData(0x14);
//    ips114_writeData(0x29);
//    ips114_writeData(0x32);
//
//    ips114_writeIndex(0x21);
//
//    ips114_writeIndex(0x11);
//    systick_delay_ms(120);
//
//    ips114_writeIndex(0x29);
//    ips114_clear(IPS114_BGCOLOR);

    ips114_writeIndex(0xFE);
    ips114_writeIndex(0xEF);

    ips114_writeIndex(0xEB);
    ips114_writeData(0x14);

    ips114_writeIndex(0x84);
    ips114_writeData(0x60);

    ips114_writeIndex(0x85);
    ips114_writeData(0xF7);

    ips114_writeIndex(0x86);
    ips114_writeData(0xFC);

    ips114_writeIndex(0x87);
    ips114_writeData(0x28);

    ips114_writeIndex(0x8E);
    ips114_writeData(0x0F);

    ips114_writeIndex(0x8F);
    ips114_writeData(0xFC);

    ips114_writeIndex(0x88);
    ips114_writeData(0x0A);

    ips114_writeIndex(0x89);
    ips114_writeData(0x21);

    ips114_writeIndex(0x8A);
    ips114_writeData(0x00);

    ips114_writeIndex(0x8B);
    ips114_writeData(0x80);

    ips114_writeIndex(0x8C);
    ips114_writeData(0x01);

    ips114_writeIndex(0x8D);
    ips114_writeData(0x01);

    ips114_writeIndex(0xB6);
    ips114_writeData(0x00);
    ips114_writeData(0x20);

    ips114_writeIndex(0x36);

    if(IPS114_DISPLAY_DIR==0)ips114_writeData(0x08);
    else if(IPS114_DISPLAY_DIR==1)ips114_writeData(0xC8);
    else if(IPS114_DISPLAY_DIR==2)ips114_writeData(0x68);
    else ips114_writeData(0xA8);

    ips114_writeIndex(0x3A);
    ips114_writeData(0x05);

    ips114_writeIndex(0x90);
    ips114_writeData(0x08);
    ips114_writeData(0x08);
    ips114_writeData(0x08);
    ips114_writeData(0x08);

    ips114_writeIndex(0xBD);
    ips114_writeData(0x06);

    ips114_writeIndex(0xBC);
    ips114_writeData(0x00);

    ips114_writeIndex(0xFF);
    ips114_writeData(0x60);
    ips114_writeData(0x01);
    ips114_writeData(0x04);

    ips114_writeIndex(0xC3);
    ips114_writeData(0x25);//48
    ips114_writeIndex(0xC4);
    ips114_writeData(0x25);

    ips114_writeIndex(0xC9);
    ips114_writeData(0x25);

    ips114_writeIndex(0xBE);
    ips114_writeData(0x11);

    ips114_writeIndex(0xE1);
    ips114_writeData(0x10);
    ips114_writeData(0x0E);

    ips114_writeIndex(0xDF);
    ips114_writeData(0x21);
    ips114_writeData(0x10);
    ips114_writeData(0x02);

    ips114_writeIndex(0xf0);
    ips114_writeData(0x4b);
    ips114_writeData(0x0f);
    ips114_writeData(0x0A);
    ips114_writeData(0x0B);
    ips114_writeData(0x15);
    ips114_writeData(0x30);

    ips114_writeIndex(0xf1);
    ips114_writeData(0x43);
    ips114_writeData(0x70);
    ips114_writeData(0x72);
    ips114_writeData(0x36);
    ips114_writeData(0x37);
    ips114_writeData(0x6f);

    ips114_writeIndex(0xf2);
    ips114_writeData(0x4b);
    ips114_writeData(0x0f);
    ips114_writeData(0x0A);
    ips114_writeData(0x0B);
    ips114_writeData(0x15);
    ips114_writeData(0x30);

    ips114_writeIndex(0xf3);
    ips114_writeData(0x43);
    ips114_writeData(0x70);
    ips114_writeData(0x72);
    ips114_writeData(0x36);
    ips114_writeData(0x37);
    ips114_writeData(0x6f);

    ips114_writeIndex(0xED);
    ips114_writeData(0x1B);
    ips114_writeData(0x0B);

    ips114_writeIndex(0xAC);
    ips114_writeData(0x47);

    ips114_writeIndex(0xAE);
    ips114_writeData(0x77);

    ips114_writeIndex(0xCD);
    ips114_writeData(0x63);

    ips114_writeIndex(0x70);
    ips114_writeData(0x07);
    ips114_writeData(0x09);
    ips114_writeData(0x04);
    ips114_writeData(0x0C);
    ips114_writeData(0x0D);
    ips114_writeData(0x09);
    ips114_writeData(0x07);
    ips114_writeData(0x08);
    ips114_writeData(0x03);

    ips114_writeIndex(0xE8);
    ips114_writeData(0x14);

/////////////////////////////////////////////
    ips114_writeIndex(0x60);
    ips114_writeData(0x38);
    ips114_writeData(0x0B);
    ips114_writeData(0x76);
    ips114_writeData(0x62);

    ips114_writeData(0x39);
    ips114_writeData(0xF0);
    ips114_writeData(0x76);
    ips114_writeData(0x62);

    ips114_writeIndex(0x61);
    ips114_writeData(0x38);
    ips114_writeData(0xF6);
    ips114_writeData(0x76);
    ips114_writeData(0x62);

    ips114_writeData(0x38);
    ips114_writeData(0xF7);
    ips114_writeData(0x76);
    ips114_writeData(0x62);
/////////////////////////////////////
    ips114_writeIndex(0x62);
    ips114_writeData(0x38);
    ips114_writeData(0x0D);
    ips114_writeData(0x71);
    ips114_writeData(0xED);
    ips114_writeData(0x76);
    ips114_writeData(0x62);
    ips114_writeData(0x38);
    ips114_writeData(0x0F);
    ips114_writeData(0x71);
    ips114_writeData(0xEF);
    ips114_writeData(0x76);
    ips114_writeData(0x62);

    ips114_writeIndex(0x63);
    ips114_writeData(0x38);
    ips114_writeData(0x11);
    ips114_writeData(0x71);
    ips114_writeData(0xF1);
    ips114_writeData(0x76);
    ips114_writeData(0x62);
    ips114_writeData(0x38);
    ips114_writeData(0x13);
    ips114_writeData(0x71);
    ips114_writeData(0xF3);
    ips114_writeData(0x76);
    ips114_writeData(0x62);

///////////////////////////////////////////////////////
    ips114_writeIndex(0x64);
    ips114_writeData(0x3b);
    ips114_writeData(0x29);
    ips114_writeData(0xF1);
    ips114_writeData(0x01);
    ips114_writeData(0xF1);
    ips114_writeData(0x00);
    ips114_writeData(0x0a);

    ips114_writeIndex(0x66);
    ips114_writeData(0x3C);
    ips114_writeData(0x00);
    ips114_writeData(0xCD);
    ips114_writeData(0x67);
    ips114_writeData(0x45);
    ips114_writeData(0x45);
    ips114_writeData(0x10);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0x00);

    ips114_writeIndex(0x67);
    ips114_writeData(0x00);
    ips114_writeData(0x3C);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0x01);
    ips114_writeData(0x54);
    ips114_writeData(0x10);
    ips114_writeData(0x32);
    ips114_writeData(0x98);

    ips114_writeIndex(0xB5);
    ips114_writeData(0x08);
    ips114_writeData(0x09);
    ips114_writeData(0x14);
    ips114_writeData(0x08);

    ips114_writeIndex(0x74);
    ips114_writeData(0x10);
    ips114_writeData(0x85);
    ips114_writeData(0x80);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0x4E);
    ips114_writeData(0x00);

    ips114_writeIndex(0x98);
    ips114_writeData(0x3e);
    ips114_writeData(0x07);

    ips114_writeIndex(0x35);
    ips114_writeData(0x00);

    ips114_writeIndex(0x21);

    ips114_writeIndex(0x11);
    systick_delay_ms(120);
    ips114_writeIndex(0x29);
    systick_delay_ms(10);




    ips114_writeIndex(0x2A);
    ips114_writeData(0x00);
    ips114_writeData(0x3C);
    ips114_writeData(0x00);
    ips114_writeData(0xb3);

    ips114_writeIndex(0x2B);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0x00);
    ips114_writeData(0xEF);

    ips114_writeIndex(0x2C);

    ips114_clear(IPS114_BGCOLOR);
}




void ips114_set_region(uint16 x1,uint16 y1,uint16 x2,uint16 y2)
{
    if(IPS114_DISPLAY_DIR==0)
    {
        ips114_writeIndex(0x2a);//�е�ַ����
        ips114_writedata_16bit(x1+0x3c);
        ips114_writedata_16bit(x2+0x3c);
        ips114_writeIndex(0x2b);//�е�ַ����
        ips114_writedata_16bit(y1);
        ips114_writedata_16bit(y2);
        ips114_writeIndex(0x2c);//������д
    }
    else if(IPS114_DISPLAY_DIR==1)
    {
        ips114_writeIndex(0x2a);//�е�ַ����
        ips114_writedata_16bit(x1+0x3c);
        ips114_writedata_16bit(x2+0x3c);
        ips114_writeIndex(0x2b);//�е�ַ����
        ips114_writedata_16bit(y1);
        ips114_writedata_16bit(y2);
        ips114_writeIndex(0x2c);//������д
    } 
    else if(IPS114_DISPLAY_DIR==2)
    {
        ips114_writeIndex(0x2a);//�е�ַ����
        ips114_writedata_16bit(x1);
        ips114_writedata_16bit(x2);
        ips114_writeIndex(0x2b);//�е�ַ����
        ips114_writedata_16bit(y1+0x3c);
        ips114_writedata_16bit(y2+0x3c);
        ips114_writeIndex(0x2c);//������д
    }
    else
    {
        ips114_writeIndex(0x2a);//�е�ַ����
        ips114_writedata_16bit(x1);
        ips114_writedata_16bit(x2);
        ips114_writeIndex(0x2b);//�е�ַ����
        ips114_writedata_16bit(y1+0x3c);
        ips114_writedata_16bit(y2+0x3c);
        ips114_writeIndex(0x2c);//������д
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����������
//  @param      color     		��ɫ����
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_clear(YELLOW);// ȫ������Ϊ��ɫ
//-------------------------------------------------------------------------------------------------------------------
void ips114_clear(uint16 color)
{
    uint16 i,j;
    ips114_set_region(0,0,IPS114_X_MAX-1,IPS114_Y_MAX-1);
    for(i=0;i<IPS114_X_MAX;i++)
    {
        for (j=0;j<IPS114_Y_MAX;j++)
        {
            ips114_writedata_16bit(color);
        }
    }
}

/******************************************************************************
      ����˵������ָ�����������ɫ
      ������ݣ�xsta,ysta   ��ʼ����
                xend,yend   ��ֹ����
								color       Ҫ������ɫ
      ����ֵ��  ��
******************************************************************************/
void ips114_Fill(uint16 xsta,uint16 ysta,uint16 xend,uint16 yend,uint16 color)
{
    uint16 i,j;
    ips114_set_region(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
    for(i=ysta;i<yend;i++)
    {
        for(j=xsta;j<xend;j++)
        {
            ips114_writedata_16bit(color);
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ������
//  @param      x     	        ����x��������
//  @param      y     	        ����y��������
//  @param      dat       	    ��Ҫ��ʾ����ɫ
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_drawpoint(0,0,RED);  //����0,0��һ����ɫ�ĵ�
//-------------------------------------------------------------------------------------------------------------------
void ips114_drawpoint(uint16 x,uint16 y,uint16 color)
{
    ips114_set_region(x,y,x,y);
    ips114_writedata_16bit(color);
}

/******************************************************************************
      ����˵��������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   �ߵ���ɫ
      ����ֵ��  ��
******************************************************************************/
void ips114_drawline(uint16 x1,uint16 y1,uint16 x2,uint16 y2,uint16 color)
{
    uint16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;
    delta_x=x2-x1; //������������
    delta_y=y2-y1;
    uRow=x1;//�����������
    uCol=y1;
    if(delta_x>0)incx=1; //���õ�������
    else if (delta_x==0)incx=0;//��ֱ��
    else {incx=-1;delta_x=-delta_x;}
    if(delta_y>0)incy=1;
    else if (delta_y==0)incy=0;//ˮƽ��
    else {incy=-1;delta_y=-delta_y;}
    if(delta_x>delta_y)distance=delta_x; //ѡȡ��������������
    else distance=delta_y;
    for(t=0;t<distance+1;t++)
    {
        ips114_drawpoint(uRow,uCol,color);//����
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

/******************************************************************************
      ����˵����������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   ���ε���ɫ
      ����ֵ��  ��
******************************************************************************/
void ips114_drawRectangle(uint16 x1, uint16 y1, uint16 x2, uint16 y2,uint16 color)
{
    ips114_drawline(x1,y1,x2,y1,color);
    ips114_drawline(x1,y1,x1,y2,color);
    ips114_drawline(x1,y2,x2,y2,color);
    ips114_drawline(x2,y1,x2,y2,color);
}

/******************************************************************************
      ����˵������Բ
      ������ݣ�x0,y0   Բ������
                r       �뾶
                color   Բ����ɫ
      ����ֵ��  ��
******************************************************************************/
void ips114_drawCircle(uint16 x0,uint16 y0,uint16 r,uint16 color)
{
    int a,b;
    a=0;b=r;
    while(a<=b)
    {
        ips114_drawpoint(x0-b,y0-a,color);             //3
        ips114_drawpoint(x0+b,y0-a,color);             //0
        ips114_drawpoint(x0-a,y0+b,color);             //1
        ips114_drawpoint(x0-a,y0-b,color);             //2
        ips114_drawpoint(x0+b,y0+a,color);             //4
        ips114_drawpoint(x0+a,y0-b,color);             //5
        ips114_drawpoint(x0+a,y0+b,color);             //6
        ips114_drawpoint(x0-b,y0+a,color);             //7
        a++;
        if((a*a+b*b)>(r*r))//�ж�Ҫ���ĵ��Ƿ��Զ
        {
            b--;
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ�ַ�
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ���ַ�
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showchar(0,0,'x');//����0,0дһ���ַ�x
//-------------------------------------------------------------------------------------------------------------------
void ips114_showchar(uint16 x,uint16 y,const int8 dat)
{
    uint8 i,j;
    uint8 temp;

    for(i=0; i<16; i++)
    {
        ips114_set_region(x,y+i,x+7,y+i);
        temp = tft_ascii[dat-32][i];//��32��Ϊ��ȡģ�Ǵӿո�ʼȡ�� �ո���ascii�������32
        for(j=0; j<8; j++)
        {
            if(temp&0x01)
            {
                ips114_writedata_16bit(IPS114_PENCOLOR);
            }
            else			ips114_writedata_16bit(IPS114_BGCOLOR);
            temp>>=1;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ�ַ���
//  @param      x     	        ����x��������  ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y��������  ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ���ַ���
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showstr(0,0,"seekfree");
//-------------------------------------------------------------------------------------------------------------------
void ips114_showstr(uint16 x,uint16 y,const int8 dat[])
{
    uint16 j;

    j = 0;
    while(dat[j] != '\0')
    {
        ips114_showchar(x+8*j,y*16,dat[j]);
        j++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ8λ�з���
//  @param      x     	        ����x��������  ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y��������  ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������int8
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showint8(0,0,x);//xΪint8����
//-------------------------------------------------------------------------------------------------------------------
void ips114_showint8(uint16 x,uint16 y,int8 dat)
{
    uint8 a[3];
    uint8 i;
    if(dat<0)
    {
        ips114_showchar(x,y*16,'-');
        dat = -dat;
    }
    else	ips114_showchar(x,y*16,' ');

    a[0] = dat/100;
    a[1] = dat/10%10;
    a[2] = dat%10;
    i = 0;
    while(i<3)
    {
        ips114_showchar(x+(8*(i+1)),y*16,'0' + a[i]);
        i++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ8λ�޷���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint8
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showuint8(0,0,x);//xΪuint8����
//-------------------------------------------------------------------------------------------------------------------
void ips114_showuint8(uint16 x,uint16 y,uint8 dat)
{
    uint8 a[3];
    uint8 i;

    a[0] = dat/100;
    a[1] = dat/10%10;
    a[2] = dat%10;
    i = 0;
    while(i<3)
    {
        ips114_showchar(x+(8*i),y*16,'0' + a[i]);
        i++;
    }

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ16λ�з���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������int16
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showint16(0,0,x);//xΪint16����
//-------------------------------------------------------------------------------------------------------------------
void ips114_showint16(uint16 x,uint16 y,int16 dat)
{
    uint8 a[5];
    uint8 i;
    if(dat<0)
    {
        ips114_showchar(x,y*16,'-');
        dat = -dat;
    }
    else	ips114_showchar(x,y*16,' ');

    a[0] = dat/10000;
    a[1] = dat/1000%10;
    a[2] = dat/100%10;
    a[3] = dat/10%10;
    a[4] = dat%10;

    i = 0;
    while(i<5)
    {
        ips114_showchar(x+(8*(i+1)),y*16,'0' + a[i]);
        i++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ16λ�޷���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint16
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showuint16(0,0,x);//xΪuint16����
//-------------------------------------------------------------------------------------------------------------------
void ips114_showuint16(uint16 x,uint16 y,uint16 dat)
{
    uint8 a[5];
    uint8 i;

    a[0] = dat/10000;
    a[1] = dat/1000%10;
    a[2] = dat/100%10;
    a[3] = dat/10%10;
    a[4] = dat%10;

    i = 0;
    while(i<5)
    {
        ips114_showchar(x+(8*i),y*16,'0' + a[i]);
        i++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ32λ�з���(ȥ������������Ч��0)
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint32
//  @param      num       	    ��Ҫ��ʾ��λ�� ���10λ  ������������
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showuint32(0,0,x,3);//x����Ϊint32 uint16 int16 uint8 int8����
//  Sample usage:               ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void ips114_showint32(uint16 x,uint16 y,int32 dat,uint8 num)
{
    int8    buff[34];
    uint8   length;

    if(10<num)      num = 10;

    num++;
    if(0>dat)   length = zf_sprintf( &buff[0],"%d",dat);//����
    else
    {
        buff[0] = ' ';
        length = zf_sprintf( &buff[1],"%d",dat);
        length++;
    }
    while(length < num)
    {
        buff[length] = ' ';
        length++;
    }
    buff[num] = '\0';

    ips114_showstr(x, y, buff);	//��ʾ����
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ������(ȥ������������Ч��0)
//  @param      x     	        ����x�������� ������Χ 0 -��IPS114_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS114_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������float��double
//  @param      num       	    ����λ��ʾ����   ���10λ  
//  @param      pointnum        С��λ��ʾ����   ���6λ
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_showfloat(0,0,x,2,3);//��ʾ������   ������ʾ2λ   С����ʾ��λ
//  @note                       �ر�ע�⵱����С��������ʾ��ֵ����д���ֵ��һ����ʱ��
//                              ���������ڸ��������ȶ�ʧ���⵼�µģ��Ⲣ������ʾ���������⣬
//                              �й���������飬�����аٶ�ѧϰ   ���������ȶ�ʧ���⡣
//                              ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void ips114_showfloat(uint16 x,uint16 y,double dat,uint8 num,uint8 pointnum)
{
    uint8   length;
    int8    buff[34];
    int8    start,end,point;

    if(6<pointnum)  pointnum = 6;
    if(10<num)      num = 10;

    if(0>dat)   length = zf_sprintf( &buff[0],"%f",dat);//����
    else
    {
        length = zf_sprintf( &buff[1],"%f",dat);
        length++;
    }
    point = length - 7;         //����С����λ��
    start = point - num - 1;    //������ʼλ
    end = point + pointnum + 1; //�������λ
    while(0>start)//����λ����  ĩβӦ�����ո�
    {
        buff[end] = ' ';
        end++;
        start++;
    }

    if(0>dat)   buff[start] = '-';
    else        buff[start] = ' ';

    buff[end] = '\0';

    ips114_showstr(x, y, buff);	//��ʾ����
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����(�Ҷ�����ͷ)Һ����ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_displayimage032(mt9v03x_csi_image[0], MT9V03X_CSI_W, MT9V03X_CSI_H)//��ʾ�Ҷ�����ͷ ͼ��
//  @note       ͼ��Ŀ����������Һ���Ŀ��ȣ����Զ�����������ʾ������������ʾȫ��Ұ
//-------------------------------------------------------------------------------------------------------------------
void ips114_displayimage032(uint8 *p, uint16 width, uint16 height)
{
    uint32 i,j;

    uint16 color = 0;
    uint16 temp = 0;

    uint16 coord_x = 0;
    uint16 coord_y = 0;

    coord_x = width>IPS114_X_MAX?IPS114_X_MAX:width;
    coord_y = height>IPS114_Y_MAX?IPS114_Y_MAX:height;
    ips114_set_region(0,0,coord_x-1,coord_y-1);

    for(j=0;j<coord_y;j++)
    {
        for(i=0;i<coord_x;i++)
        {
            temp = *(p+j*width+i*width/coord_x);//��ȡ���ص�
            color=(0x001f&((temp)>>3))<<11;
            color=color|(((0x003f)&((temp)>>2))<<5);
            color=color|(0x001f&((temp)>>3));
            ips114_writedata_16bit(color);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����(�Ҷ�����ͷ)Һ��������ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @param      dis_width       ͼ����ʾ����  1 -��IPS114_X_MAX��
//  @param      dis_height      ͼ����ʾ�߶�  1 -��IPS114_Y_MAX��
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_displayimage032_zoom(mt9v03x_csi_image[0], MT9V03X_CSI_W, MT9V03X_CSI_H, MT9V03X_CSI_W, MT9V03X_CSI_H)//��ʾ�Ҷ�����ͷ ͼ��
//  @note       ͼ��Ŀ����������Һ���Ŀ��ȣ����Զ�����������ʾ������������ʾȫ��Ұ
//-------------------------------------------------------------------------------------------------------------------
void ips114_displayimage032_zoom(uint8 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height)
{
    uint32 i,j;

    uint16 color = 0;
    uint16 temp = 0;

    ips114_set_region(0,0,dis_width-1,dis_height-1);//������ʾ���� 

    for(j=0;j<dis_height;j++)
    {
        for(i=0;i<dis_width;i++)
        {
            temp = *(p+(j*height/dis_height)*width+i*width/dis_width);//��ȡ���ص�
            color=(0x001f&((temp)>>3))<<11;
            color=color|(((0x003f)&((temp)>>2))<<5);
            color=color|(0x001f&((temp)>>3));
            ips114_writedata_16bit(color);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����(�Ҷ�����ͷ)Һ��������ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @param      start_x         ������ʾ����x������
//  @param      start_y     	������ʾ����y������
//  @param      dis_width       ͼ����ʾ����  1 -��IPS114_X_MAX��
//  @param      dis_height      ͼ����ʾ�߶�  1 -��IPS114_Y_MAX��
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_displayimage032_zoom1(mt9v03x_csi_image[0], MT9V03X_CSI_W, MT9V03X_CSI_H, 0, 0, MT9V03X_CSI_W, MT9V03X_CSI_H)//��ʾ�Ҷ�����ͷ ͼ��
//-------------------------------------------------------------------------------------------------------------------

void ips114_displayimage032_zoom1(uint8 *p, uint16 width, uint16 height, uint16 start_x, uint16 start_y, uint16 dis_width, uint16 dis_height)
{
    uint32 i,j;

    uint16 color = 0;
    uint16 temp = 0;

    //������õĲ����Ƿ񳬹���Ļ�ķֱ���
    if((start_x+dis_width)>IPS114_X_MAX)	assert(0);
    if((start_y+dis_height)>IPS114_Y_MAX)	assert(0);
    ips114_set_region(start_x,start_y,start_x+dis_width-1,start_y+dis_height-1);//������ʾ���� 

    for(j=0;j<dis_height;j++)
    {
        for(i=0;i<dis_width;i++)
        {
            temp = *(p+(j*height/dis_height)*width+i*width/dis_width);//��ȡ���ص�
            color=(0x001f&((temp)>>3))<<11;
            color=color|(((0x003f)&((temp)>>2))<<5);
            color=color|(0x001f&((temp)>>3));
            ips114_writedata_16bit(color);
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ͫ(��ɫ����ͷ)Һ��������ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @param      dis_width       ͼ����ʾ����  0 -��TFT_X_MAX-1��
//  @param      dis_height      ͼ����ʾ�߶�  0 -��TFT_Y_MAX-1��
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_displayimage8660_zoom(scc8660_csi_image[0], SCC8660_CSI_PIC_W, SCC8660_CSI_PIC_H, 320, 240)//��ʾ��ɫ����ͷ ͼ��
//  @note       ͼ��Ŀ����������Һ���Ŀ��ȣ����Զ�����������ʾ������������ʾȫ��Ұ
//-------------------------------------------------------------------------------------------------------------------
void ips114_displayimage8660_zoom(uint16 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height)
{
    uint32 i,j;
    uint16 color = 0;

    ips114_set_region(0,0,dis_width-1,dis_height-1);//������ʾ���� 

    for(j=0;j<dis_height;j++)
    {
        for(i=0;i<dis_width;i++)
        {
            color = *(p+(j*height/dis_height)*width+i*width/dis_width);//��ȡ���ص�
            color = ((color&0xff)<<8) | (color>>8);
            ips114_writedata_16bit(color);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ͫ(��ɫ����ͷ)Һ��������ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @param      start_x         ������ʾ����x������
//  @param      start_y     	������ʾ����y������
//  @param      dis_width       ͼ����ʾ����  1 -��TFT_X_MAX��
//  @param      dis_height      ͼ����ʾ�߶�  1 -��TFT_Y_MAX��
//  @return     void
//  @since      v1.0
//  Sample usage:               ips114_displayimage8660_zoom1(scc8660_csi_image[0], SCC8660_CSI_PIC_W, SCC8660_CSI_PIC_H, 0, 0, 320, 240);
//-------------------------------------------------------------------------------------------------------------------
void ips114_displayimage8660_zoom1(uint8 *p, uint16 width, uint16 height, uint16 start_x, uint16 start_y, uint16 dis_width, uint16 dis_height)
{
    uint32 i,j;

    uint16 color = 0;

    //������õĲ����Ƿ񳬹���Ļ�ķֱ���
    if((start_x+dis_width)>IPS114_X_MAX)	assert(0);
    if((start_y+dis_height)>IPS114_Y_MAX)	assert(0);

    ips114_set_region(start_x,start_y,start_x+dis_width-1,start_y+dis_height-1);//������ʾ���� 

    for(j=0;j<dis_height;j++)
    {
        for(i=0;i<dis_width;i++)
        {
            color = *(p+(j*height/dis_height)*width+i*width/dis_width);//��ȡ���ص�
            color = ((color&0xff)<<8) | (color>>8);
            ips114_writedata_16bit(color);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      С���(��ֵ������ͷ)Һ����ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ�����
//  @param      height     	    ͼ��߶�
//  @return     void
//  @since      v1.0
//  @note      	ͼ��ֱ�����Ҫ������120(��)*160(��)����       
//-------------------------------------------------------------------------------------------------------------------
void ips114_displayimage7725(uint8 *p, uint16 width, uint16 height)
{
    int i,j;

    uint16 temp = 0;
    ips114_set_region(0,0,width-1,height-1);
    for(i=0;i<height * (width/8);i++)
    {
        temp = *p;
        p++;
        for(j=0; j<8; j++)
        {
            if( (temp<<j)&0x80 )	ips114_writedata_16bit(WHITE);
            else					ips114_writedata_16bit(BLACK);
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ������ʾ
//  @param      x       ������ 0-��IPS114_X_MAX-1��
//  @param      y       ������ 0-��IPS114_Y_MAX-1��
//  @param      size    ȡģ��ʱ�����õĺ��������С��Ҳ����һ������ռ�õĵ��󳤿�Ϊ���ٸ��㣬ȡģ��ʱ����Ҫ������һ���ġ�
//  @param      *p      ��Ҫ��ʾ�ĺ�������
//  @param      number  ��Ҫ��ʾ����λ
//  @param      color   ��ʾ��ɫ
//  @return     void
//  @since      v1.0
//  Sample usage:		ips114_display_chinese(0,0,16,chinese_test[0],4,RED);//��ʾfont�ļ������ ʾ��
//  @Note       ʹ��PCtoLCD2002����ȡģ		    ���롢����ʽ��˳��   16*16
//-------------------------------------------------------------------------------------------------------------------
void ips114_display_chinese(uint16 x, uint16 y, uint8 size, const uint8 *p, uint8 number, uint16 color)
{
    int i, j, k;
    uint8 temp, temp1, temp2;
    const uint8 *p_data;

    temp2 = size/8;

    ips114_set_region(x,y,number*size-1+x,y+size-1);

    for(i=0;i<size;i++)
    {
        temp1 = number;
        p_data = p+i*temp2;
        while(temp1--)
        {
            for(k=0;k<temp2;k++)
            {
                for(j=8;j>0;j--)
                {
                    temp = (*p_data>>(j-1)) & 0x01;
                    if(temp)    ips114_writedata_16bit(color);
                    else        ips114_writedata_16bit(IPS114_BGCOLOR);
                }
                p_data++;
            }
            p_data = p_data - temp2 + temp2*size;
        }
    }
}

