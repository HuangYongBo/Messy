#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "read_cfg.h"

struct cfg_info read_info;

int read_data()
{
	struct file *fp;
	int pos;
	int i,j;
	
	fp = filp_open("/dev/block/config_data",O_RDONLY,0);
	if (IS_ERR(fp)) 
	{
       		printk("open file error\n");
		return -1;
	}
	
	char num;
	pos = 0;
	ret = vfs_read(fp, num, sizeof(num), &pos);
	if(ret < 0)
	{
		printk("read error\r\n");
		return -1;
	}
	for(i = 0;i < num;i++)
	{
		memset(&read_info,'0',sizeof(read_info));
		pos = 1+i*sizeof(read_info);
		vfs_read(fp,&read_info,sizeof(read_info),pos);
		printk("read_info: %s , %d ,%d\r\n",read_info.name,read_info.addr_off,read_info.size);
		if(!memcmp(read_info.name,"touch_cfg",9))
		{
			break;
		}

	}
	if(i == num)
	{
		printk("can not find touch config data \r\n");
		return -1;
	}
		
	
	char buf[read_info.size];
	pos = read_info.addr_off;
	ret = vfs_read(fp,&buf,read_info.size,pos);
	if(ret != read_info.size)
	{
		printk("read config data error\r\n");	
		return -1;
	}
	
	for(j = 0;j < read_info.size; j++)
	{
		printk("%#x",buf[j]);
		if(j%10 && j!= 0 )
			printk("\r\n");
	}
			printk("\r\n");
	
	return 0;
}
