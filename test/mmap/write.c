#include "myhead.h"

int main(int argc,char* argv[])
{
	umask(0000);	
	int fd = open(PATH,O_RDWR|O_CREAT,0664);
	if( -1 == fd)
	{
		printf("open filed %d :%s",errno,strerror(errno));
		exit(-1);
	}
			
	char *map;
	int file_size = 1024;
	map =(char*)mmap(NULL,file_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if(MAP_FAILED == map)
	{
		printf("map filed %d :%s",errno,strerror(errno));
		exit(-1);
	}
	ftruncate(fd,file_size);
	char str[100] = {0};
	int str_size = 0;
	int ret = 0;
	int time;
	
	do{
		memset(str,0,100);
		scanf("%s",str);
		ret = strlen(str);
		printf("strlen %d: %s\n",ret,str);
	
		if(str_size + ret > file_size)
		{
			munmap(map,file_size);
			file_size += 1024;
			time = 0;
			do
			{
				map =(char*)mmap(NULL,file_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
			}while(time < 3 && MAP_FAILED == map);
		}
		memcpy(map+str_size,str,ret);
		str_size +=ret;
		ftruncate(fd,str_size);
		printf("\t---all size:%d---\n",str_size);
			
		getchar();
		printf("push \'q\' to quit\n");
	}
	while('q' != getchar() );

	munmap(map,file_size);
	return 0;
}

