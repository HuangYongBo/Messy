#include <my_upgrade.h>
#include <select.h>

void select_setup(int i)
{
	switch(i)
	{
		case 1:
			{	
				char str[] = "mmc read 0 0x6000000 0xb000 0x2000;mmc read 0 0x7000000 0xd000 0x1000;bootm 0x6000000";
				printf("select kernel \r\n");
				run_command(str,0);
			
				break;
			}
		case 0:
			{
				char str[] = "mmc read 0 0x7000000 0x202000 0x2000;mmc read 0 0x6000000 0xb000 0x2000;bootm 0x6000000";
				printf("select recovery \r\n");
				run_command(str,0);
				break;

			}
		default:
			printf("select nothing \r\n");
			break;

	}
}


void select_touch()
{
	int x,y;
	int flag = 0;
	int tmp;
	lcd_setbg(0,0,LCD_WIDTH,LCD_HIGHT,0x3c557d);
	lcd_drawround_bydiameter(156,200,200,0,0xFF0000,NULL);
	lcd_drawround_bydiameter(668,200,200,0,0xFF00,NULL);
	lcd_drawstring(668,275,50,"recovery",NULL,NULL);
	lcd_drawstring(181,275,50,"kernel",NULL,NULL);
	reset_panel();
	init_panel();
	while(!flag)
	{
		mdelay(20);
		flag = get_touch_status_pos_xy(&x,&y);
	}
	if(668<= y && 868 >= y && 200<=x && 400>=x)//touch recovery  //触摸屏x,y轴相反，
	{

		select_setup(0);

	}else if(156 <= y && 356>= y && 200<= x && 400 >= x)
	{
		select_setup(1);
	}else
	{
		printf("[touch] %d,%d\r\n",x,y);
	}
	/*if(668<= x && 868 >= x && 200<=y && 400>=y)//touch recovery
	{

		select_setup(0);

	}else if(156 <= x && 356>= x && 200<= y && 400 >= y)
	{
		select_setup(1);
	}else
	{
		printf("[touch] %d,%d\r\n",x,y);
	}*/
	my_test();


}
