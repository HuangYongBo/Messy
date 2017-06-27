#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "read_cfg.h"

#define CFG_DATA_OFFSET 0x57000000

int main(int argc ,char *argv[])
{
	int fd;
	int ret;
	int i,j;
	struct cfg_info read_info;	
	if(argc != 2)
	{
		printf("Usage: %s [filepath\r\n]",argv[0]);
		return -1;
	}
	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		printf("open error\r\n");
		return -1;
	}
	lseek(fd,CFG_DATA_OFFSET,SEEK_SET);
	
	char num;
	ret = read(fd,&num,1);
	if(ret < 0)
	{
		printf("read error\r\n");
		return -1;
	}
	for(i = 0;i < num;i++)
	{
		memset(&read_info,'0',sizeof(read_info));
		read(fd,&read_info,sizeof(read_info));
		printf("read_info: %s , %d ,%d\r\n",read_info.name,read_info.addr_off,read_info.size);
		if(!strncmp(read_info.name,"touch_cfg",9))
		{
			break;
		}

	}
	if(i == num)
	{
		printf("can not find touch config data \r\n");
		return -1;
	}
		
	
	char buf[read_info.size];
	lseek(fd,CFG_DATA_OFFSET+read_info.addr_off,SEEK_SET);
	ret = read(fd,&buf,read_info.size);
	if(ret != read_info.size)
	{
		printf("read config data error\r\n");	
		return -1;
	}
	
	for(j = 0;j < read_info.size; j++)
	{
		printf("%#x",buf[j]);
		if(j%10 && j!= 0 )
			printf("\r\n");
	}
			printf("\r\n");
	
	return 0;
}
