//
// Created by Jay on 2022/4/7.
//

#ifndef _LOCATION_H
#define _LOCATION_H


#include "headfile.h"


//-----------------------宏-----------------------//
#define locate_sz 10             //坐标数组数量,可能还需要更改，目标点数不确定！
//---------------------数组-----------------------//
extern float location_X[locate_sz];    //x坐标存放处
extern float location_Y[locate_sz];    //y坐标存放处
//--------------------全局变量---------------------//
extern struct Location_Goal Car;
//---------------------结构体---------------------//
//记录坐标和相对位置的结构体
typedef struct Location_Goal
{
    //已到达的目标点
    int8_t Position_Pointer;
    //当前位置
    float x;
    float y;
    //目标位置
    float x1;
    float y1;
    //当前姿态
    float Angel;
    //目标姿态
    float Angel_Target;
    //目标距离
    float Distance;
    //距上次转向之后前进的距离(里程）
    float mileage;
    //模式标志位:1->行进模式||0->识别模式
    int8_t Mode_Flag;
}Location_Goal;


//-------------------函数定义---------------------//

void Charge_Locate(void);            //坐标处理函数
void Get_Road(void);                 //路径呈现函数

#endif 
