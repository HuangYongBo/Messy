
#include <my_upgrade.h>
extern char CharBitmap50x25[][200];
extern char CharBitmap36x18[][108];

uint  *lpFrameBuf=FRAMEBUFFER_MEM_PA ;

char CharFontArray[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','S','Y','Z',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
'0','1','2','3','4','5','6','7','8','9',',','.','/',':',';','\'','"','!','%',
};

char char_type[]={50,36};
char *Font[]={CharBitmap50x25,CharBitmap36x18};
void lcd_drawring_bydiameter(ushort x,ushort y,ushort diameter,ushort size,uint color)
{
	ushort OD,ID,x2,y2;
	OD = diameter/2;
	ID = OD - size;
	x2 = x + OD;
	y2 = y + OD;
	lcd_drawring_byradius(x2,y2,ID,OD,color);

}
void lcd_drawring_byradius(ushort x,ushort y,ushort ID,ushort OD,uint color)
//inside and outside diameters
{
	uint max_x;
	uint min_x;
	uint max_y;
	uint min_y;
	uint  *lpFrameBuf;
	
	lpFrameBuf =FRAMEBUFFER_MEM_PA ;
	max_x = (x+OD > LCD_WIDTH)?(LCD_WIDTH):(max_x+OD);
	min_x = (x-OD < 0)?(0):(x-OD);
	max_y = (y+OD > LCD_HIGHT)?(LCD_HIGHT):(y+OD);
	min_y = (y-OD < 0)?(0):(y-OD);

	
	//off = x *(1<<LCD_BPP)%8;
	int i,j,distance;
 	for(i = min_y;i < max_y;i++)
	{
		for(j=min_x;j< max_x;j++)
		{
			distance = (j-x)*(j-x)+(i-y)*(i-y); 
			if(OD*OD >= distance && ID*ID <=distance)
			{
				*(lpFrameBuf+i*LCD_WIDTH+j)=color;
			}		
		}
	}
}

void lcd_drawround_bydiameter(ushort x,ushort y,ushort diameter,uchar rate,uint color1,uint color2)
{
	ushort x2,y2,r;
	r = diameter/2;
	x2 = x+r;
	y2 = y+r;
	lcd_drawround_byradius(x2,y2,r,rate,color1,color2);	

}

void lcd_drawround_byradius(ushort x,ushort y,ushort r,uchar rate,uint color1,uint color2)
{
	int i,j,distance,tmp;
	uint max_x;
	uint min_x;
	uint max_y;
	uint min_y;
	uint  *lpFrameBuf;
	
	lpFrameBuf =FRAMEBUFFER_MEM_PA ;
	max_x = (x+r > LCD_WIDTH)?(LCD_WIDTH):(x+r);
	max_y = (y+r > LCD_HIGHT)?(LCD_HIGHT):(y+r);
	min_x = (x-r < 0)?(0):(x-r);
	min_y = (y-r < 0)?(0):(y-r);
	for(i  = min_y;i < max_y;i++)
	{
		for(j  = min_x;j < max_x;j++)
		{
			distance = (j-x)*(j-x)+(i-y)*(i-y);
			tmp = y+r-2*r*rate/100;
			if(distance <= r*r)
			{
				if(i>tmp)
				{
					*(lpFrameBuf+i*LCD_WIDTH+j)=color2;
				}else
				{
					*(lpFrameBuf+i*LCD_WIDTH+j)=color1;
				}
			} 
		}
	}
}
void lcd_setbg(ushort x,ushort y,ushort width,ushort hight,uint color)
{
    int i, j;
	uint  *lpFrameBuf;
	
	lpFrameBuf =FRAMEBUFFER_MEM_PA ;
	
    for (i = y; i < y+hight; i++)
    {   
        for (j = x; j < x+width; j++)
        {
            *(lpFrameBuf+i*LCD_WIDTH+j)=color;
        }
    }

}
void lcd_drawchar(ushort x,ushort y,ushort type,char c,uint bkcolor,uint fgcolor)
{
	int i,j,k,idx;
	
	int row = (type/2%8)?((type/2+8)/8):(type/2/8);
	int CharCount = sizeof(CharFontArray)/sizeof(CharFontArray[0]);
	uint  *lpFrameBuf;
	char *p= NULL;
	lpFrameBuf =FRAMEBUFFER_MEM_PA ;
	for(i = 0;i<sizeof(char_type);i++)
	{	
		if(type == char_type[i])
		{
			p=Font[i];	
			break;
		}
	}
	//printf("[LCD_DRAW]i = %d,type = %d\r\n",i,char_type[i]);
	//printf("[LCD_DRAW]p:%p,Char50x25:%p\r\n",p,CharBitmap50x25);
	if(p==NULL)
	{
		printf("[LCD_DRAW]Font type  error\r\n");
		return ;
	}
	for(idx = 0;idx<CharCount;idx++)
	{
		if(c == CharFontArray[idx])
		break;
	}
	if(idx >= CharCount)
	{
		printf("[LCD_DRAW]This Font no have %c\r\n",c);
		return;
	}
	for(i=0;i<type;i++)
	{
		for(j=0;j<row;j++)
		{
			//printf("[LCD_DARW]0x%x",*(p+idx*type*row+i*row+j));
			//printf("[LCD_DARW]0x%x",p[idx][i*row+j]);
			for(k=0;k<8;k++)
			{
				//if(p[idx][i*row+j] & (0x80>>j))
				if(*(p+idx*type*row+i*row+j) & (0x1<<k))
				{
					*(lpFrameBuf+(y+i)*LCD_WIDTH+j*8+x+k)=((fgcolor)?(fgcolor):(DEFAULT_FGCOLOR));
				}
				else
				{
					if(NULL==bkcolor) continue;
					*(lpFrameBuf+(y+i)*LCD_WIDTH+j*8+x+k)=bkcolor;
				}//end if
			}//end for
		}//end for
	}//end for
	//printf("i:%d,j:%d,k:%d\r\n",i,j,k);
}

void lcd_drawstring(ushort x,ushort y,ushort type,char* str,uint bkcolor,uint fgcolor)
{
	int i,j,curxpos,curypos;
	curxpos = x;
	curypos = y;
	if(NULL == str)
	{
		return ;
	}
	for(i=0;str[i]!=0;i++)
	{
		if('\n' == str[i])
		{
			curxpos = x;
			curypos += type;
		}
		else
		{
			lcd_drawchar(curxpos,curypos,type,str[i],bkcolor,fgcolor);
			curxpos += type/2;
		}
		
	}
	
	
}
void _delay()
{
	int i,j;
	i = 300;
	
	while(i!=0)
	{
		j = 300;
		while(j!=0)
		{
			printf("%c",'\0');
			j--;
		}
		i--;
		
	}

		
	
	
}

void progress_bar(int rate)
{
	static int time = 0;
	static int last = 0;
	
	if(rate > 100 || rate < -1)
	{
		printf("[PROGRESS BAR] error progress rate \r\n");
		return ;
	}
//	if(!(last>0 && rate <100 && rate >0))
	if(!time)//first drawing needs to draw the background
	{
		lcd_setbg(0,0,LCD_WIDTH,LCD_HIGHT,0x3c557d);
		lcd_drawring_bydiameter(380,112,264,16,0x292e43);
		lcd_drawring_bydiameter(396,128,232,18,0x0);
		time = 1;
	}
	if((-1 == rate &&  -1 !=last)||(rate >= 0 &&  -1 == last)|| (100 == rate  && last > 0))
	{//clear string
		lcd_setbg(432,420,10*36,36,0x3c557d);
	}
	last = rate;

	if(-1 == rate)//error
	{
		lcd_drawround_bydiameter(414,146,196,100,NULL,0xda0000);
		lcd_drawstring(450,220,50,"ERROR",NULL,NULL);
		lcd_drawstring(458,420,36,"Failed",NULL,NULL);
	}else if(0 <= rate && rate <= 99)
	{
		char str[2]={0};
		sprintf(str,"%d",rate);
		lcd_drawround_bydiameter(414,146,196,rate,0x3c557d,0x245d0);		
		lcd_drawstring(480,220,50,str,NULL,NULL);
		lcd_drawchar(530,220,50,'%',NULL,NULL);
		lcd_drawstring(432,420,36,"Upgrading",NULL,NULL);
		

	}else if(100 == rate)
	{

		lcd_drawround_bydiameter(414,146,196,100,NULL,0x00d90a);
		lcd_drawstring(487,220,50,"OK",NULL,NULL);
		lcd_drawstring(432,420,36,"Finished",NULL,NULL);

	}
	

} 


void my_test() 
{
	int i;
	for(i = -1;i<=100;i++)
	{
		progress_bar(i);
		if(i<30)
		_delay();
	}	
		_delay();
		_delay();
		

}
