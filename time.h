/****************************************************************************
* 文 件 名: time.h
* 作    者: Qiao Yu
* 修    订: 2019-01-28
* 版    本: 1.0
* 描    述: 设置串口调试助手波特率：115200bps 8N1
*           串口调试助手给CC254x发字符串时，开发板会返回接收到的字符串
****************************************************************************/
#ifndef __TIME_H
#define __TIME_H	 

#include <ioCC2540.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned int  uint;



/****************************************************************************
* 函数声明
****************************************************************************/
void DelayUS(uint usec);
void DelayMS(uint msec);
void InitTime(void);

#endif
