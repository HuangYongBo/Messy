
#ifndef _MY_UPGRADE_H_
#define _MY_UPGRADE_H_
#include <config.h>
#include <common.h>
#include <command.h>
#include <stdarg.h>
#include <linux/types.h>
#include <lcd.h>
#include <watchdog.h>
#include <ac83xx_memory.h>
#include <stdio_dev.h>
//#define FRAMEBUFFER_MEM_PA 11
#define ushort unsigned short
#define uint unsigned int
#define uchar unsigned char
#define LCD_WIDTH 1024
#define LCD_HIGHT 600
//#define DEFAULT_BKCOLOR
#define DEFAULT_FGCOLOR  0xFFFFFFFF
void lcd_setbg(ushort x,ushort y,ushort width,ushort hight,uint color);
void lcd_drawring_bydiameter(ushort x,ushort y,ushort diameter,ushort size,uint color);
void lcd_drawring_byradius(ushort x,ushort y,ushort ID,ushort OD,uint color);
void lcd_drawround_byradius(ushort x,ushort y,ushort r,uchar rate,uint color1,uint color2);
void lcd_drawround_bydiameter(ushort x,ushort y,ushort diameter,uchar rate,uint color1,uint color2);

void lcd_drawchar(ushort x,ushort y,ushort type,char c,uint bkcolor,uint fgcolor);
void lcd_drawstring(ushort x,ushort y,ushort type,char* str,uint bkcolor,uint fgcolor);
void my_test();
void _delay();
void progress_bar(int rate);
#endif
