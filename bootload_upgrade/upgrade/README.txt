/********************          主要功能           ***********************/
此包的实现的主要功能是升级时的界面效果。



/*********************          文件说明         ************************/
Charbitmapxx.c  :屏幕上显示字体的字模，xx表示大小,暂时只添加了50和36大小的英文字符和部分符号.
my_upgrade.h    :头文件
my_upgrade.c    :源文件


/*********************          使用说明         ************************/
如需使用该包，建议按照以下步骤将其添加到uboot工程中。
1.将这个目录完整的拷贝到~/ac8xx7_src/autochips/platform/uboot/uboot-83xx/common 目录下
2.将*.h文件放到~/ac8xx7_src/autochips/platform/uboot/uboot-83xx/include 目录中
3.在~/ac8xx7_src/autochips/platform/uboot/uboot-83xx/Makefile中的合适位置添加如下代码：

LIBS += common/upgrade/libupgrade.a
TAG_SUBDIRS += common/upgrade

两条命令作用分别为：添加指定静态库 和 添加工程包目录。



/*********************          函数说明         ************************/

函数声明：void lcd_setbg(ushort x,ushort y,ushort width,ushort hight,uint color);
功能：设置屏幕背景颜色
参数：x,y:育设置屏幕的起始坐标
	  width，hight：需要设置的宽和高
	  color：设置的颜色
例程：lcd_setbg(0,0,100,100,0xffffff);//将坐标属于 0<x<100,0<y<100中的像素点设成0xffffff(白色)





函数声明:void lcd_drawring_byradius(ushort x,ushort y,ushort ID,ushort OD,uint color);
功能：画圆环
参数：x,y:圆环圆心坐标
	  ID:圆环的内圆直径
	  OD:圆环的外圆直径
	  color：圆环的颜色
例程：lcd_drawring_byradius(200,200,100,120,0xffffff);

函数声明:void lcd_drawround_byradius(ushort x,ushort y,ushort r,uchar rate,uint color1,uint color2);
功能：按百分比将圆画上下分成两部分，分别显示两种颜色
参数：x,y:圆的圆心坐标
	  r：圆的半径
	  rate：百分比，该百分比为圆的下部分比例
	  color1：上部分的颜色
	  color2：下部分的颜色
例程：lcd_drawround_byradius(200,200,100,50,0x0,0xffffff);
		//将半径为100，圆心在200，200的圆分成两部分，上部分显示黑(0x0),下部分显示白(0xffffff)


函数声明:void lcd_drawring_bydiameter(ushort x,ushort y,ushort diameter,ushort size,uint color);
功能：画圆环
参数：x,y:圆环所在正方形区域的左上角坐标
	  diameter:圆环的外圆直径
	  size：圆环的像素点
	  color：圆环的颜色
说明：该函数是对lcd_drawring_byradius()函数的封装，用于简化计算参数
例程：lcd_drawring_bydiameter(0,0,100,16,0xffffff);

函数声明:void lcd_drawround_bydiameter(ushort x,ushort y,ushort diameter,uchar rate,uint color1,uint color2);
功能：按百分比将圆画上下分成两部分，分别显示两种颜色
参数：x,y:圆所在正方形区域的左上角坐标
	  diameter：圆的半直径
	  rate：百分比，该百分比为圆的下部分比例
	  color1：上部分的颜色
	  color2：下部分的颜色
说明：该函数是对lcd_drawring_byradius()函数的封装，用于简化计算参数
例程：lcd_drawround_bydiameter(150,150,100,50,0x0,0xffffff);
		//将半径为100，圆心在200(150+50)，200(150+50)的圆分成两部分，上部分显示黑(0x0),下部分显示白(0xffffff)


void lcd_drawchar(ushort x,ushort y,ushort type,char c,uint bkcolor,uint fgcolor);
功能：在屏幕上显示字符
参数：x,y:字符显示的起始坐标
	  type:字符的大小（以像素点为大小）
	  c:将显示的字符
	  bkcolor:字符背景颜色，可设置为NULL，即不画背景色
	  fgcolor:字符颜色，可设置为NULL，即默认为白色
例程：lcd_drawchar（0,0,50,'Y',NULL,NULL);
	  

void lcd_drawstring(ushort x,ushort y,ushort type,char* str,uint bkcolor,uint fgcolor);
功能：在屏幕上显示字符串
参数：x,y:字符串显示的起始坐标
	  type:字符的大小（以像素点为大小）
	  str:将显示的字符串
	  bkcolor:字符背景颜色，可设置为NULL，即不画背景色
	  fgcolor:字符颜色，可设置为NULL，即默认为白色
例程：lcd_drawchar（0,0,50,"Hellow world",NULL,NULL);


void progress_bar(int rate)
功能：显示升级进度图
参数：rate:进度比例 （取值范围为-1~100，-1为失败，0~99升级中，100升级成功)



void _delay();
功能：用于延迟



void my_test();//测试代码



	
