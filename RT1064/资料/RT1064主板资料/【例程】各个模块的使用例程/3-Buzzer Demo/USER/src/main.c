/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.24
 * @Target core		NXP RT1064DVL6A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-30
 * @note		    
 					接线定义：
					------------------------------------ 
					蜂鸣器          单片机                        
					BUZZER			查看main.c文件中的BUZZER_PIN宏定义
					------------------------------------ 
 ********************************************************************************************************************/


//整套推荐IO查看Projecct文件夹下的TXT文本



//打开新的工程或者工程移动了位置务必执行以下操作
//第一步 关闭上面所有打开的文件
//第二步 project  clean  等待下方进度条走完



#include "headfile.h"

#define BEEP_PIN   B11       //定义蜂鸣器引脚


int main(void)
{
    
    DisableGlobalIRQ();
    board_init();   //务必保留，本函数用于初始化MPU 时钟 调试串口
    
	systick_delay_ms(300);	//延时300ms，等待主板其他外设上电成功
	
	
    //初始化蜂鸣器引脚
    gpio_init(BEEP_PIN,GPO,0,GPIO_PIN_CONFIG);
	
    EnableGlobalIRQ(0);

    while(1)
    {
        gpio_set(BEEP_PIN,0);//关闭蜂鸣器
        systick_delay_ms(1000);
        gpio_set(BEEP_PIN,1);//打开蜂鸣器
        systick_delay_ms(1000);
    }

    
}





