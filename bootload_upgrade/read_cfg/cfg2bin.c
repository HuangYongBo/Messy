#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "read_cfg.h"

#define BUF_SIZE 512

#define uchar unsigned char

char char2num(char c)
{
	if('0' <= c && '9' >= c)
	{	
		return c-'0';
	}
	else if('A' <= c && 'F' >= c)
	{
		return c - 'A' +10;
	}
	else if('a' <= c && 'f' >= c)
	{
		return c - 'a' +10;
	}else
	{
		printf("error parameter:%c\n",c);
		return -1;
	}

}
int main(int argc ,char *argv[])
{
	if(argc != 3)
	{
		printf("Uage:%s  [filename] [data_type]\n",argv[0]);
		return -1;
	}
	struct stat file_info;
	stat(argv[1],&file_info);
	if(!S_ISREG(file_info.st_mode))
	{
		printf("file type error\n");
		return -1;
	}

	/*read data*/
	int  fd = open(argv[1],O_RDONLY);	
	int ret ;
	char buf[file_info.st_size];
	ret = read(fd,buf,file_info.st_size);
	if(ret != file_info.st_size)
	{
		printf("read error\n");
		close(fd);
		return -1;
	}
	
	close(fd);
	/*deal with data*/
	char *p;
	char delim[]=" ,\n";
	char cfg_data[(file_info.st_size+1)/5];
	int count = 0;
	p = strtok(buf,delim);
	do
	{	
		if(*p == '0')
		{
			if(*(p+1) == 'x' || *(p+1) == 'X')
			{
				cfg_data[count] = char2num(*(p+2))*16
						+char2num(*(p+3));
				count++;		
			}
		}		
		p = strtok(NULL,delim);
	}while(p!=NULL);

	if(count != (file_info.st_size+1)/5)
	{
		printf("deal with data error \n");
		return -1;
	}


	int i;
	for(i=0;i<CUR_INFO_NUM;i++)
	{
		if(!strcmp(argv[2],TYPE[i]))
		break;
	}
	if(i == CUR_INFO_NUM)
	{
		printf("config type can't find\n");
		return -1;
	}

	struct cfg_info info;
	int len = strlen(argv[2]);
	int off;

	memcpy(info.name,argv[2],(len>16)?16:len);
//	printf("name :%s len :%d \n",info.name,len);				
	info.addr_off  = i*CFG_DATA_SIZE + (10*sizeof(struct cfg_info)) + 1;
	info.size  = count ;
	printf("info.size :%d\n",info.size);
	fd =open("config_data.bin",O_RDWR|O_CREAT,0644);
	if(fd == -1)
	{
		printf("create file error \n");
		return -1;
	}
	
	//set first byte :save current info number
	lseek(fd,0,SEEK_SET);
	char num = CUR_INFO_NUM;
	ret = write(fd,&num,1);
	if(ret == -1)
	{
		printf("write cur_info_num error\n");
		return -1;
	}

#ifdef DEBUG
	lseek(fd,0,SEEK_SET);
	read(fd,&num,1);
	printf("%d\n ",num);
#endif
	off = i*sizeof(struct cfg_info) + 1; 
	printf("%d ",off);
	lseek(fd,off,SEEK_SET);
	ret = write(fd,&info,sizeof(struct cfg_info));
	if(ret == -1)
	{
		printf("write cfg_info error\n");
		return -1;
	}

	off = 1 + MAX_INFO_NUM*sizeof(struct cfg_info) +i*CFG_DATA_SIZE;
	printf(" %d \r\n ",off);
	lseek(fd,off,SEEK_SET);
	ret = write(fd,&cfg_data,count);
	if(ret == -1)
	{
		printf("write cfg_data error\n");
		return -1;
	}

	close(fd);	
	return 0;
}
