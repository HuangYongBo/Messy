#include "myhead.h"



int get_file_size(char *path)
{
//	if()//file is 
	struct stat file_info;
	stat(path,&file_info);

	
	return file_info.st_size;

}

int main(int argc,char* argv[])
{
	umask(0000);	
	int fd = open(PATH,O_RDWR,0664);
	if( -1 == fd)
	{
		printf("open filed %d :%s",errno,strerror(errno));
		exit(-1);
	}
			
	char *map;
	int map_size = 1024;
	int file_size;


	do
	{

		file_size = get_file_size(PATH);
		if(map_size < file_size)	
		{
			map =(char*)mmap(NULL,map_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
			if(MAP_FAILED == map)
			{
				printf("map filed %d :%s",errno,strerror(errno));
				exit(-1);
			}
		}
		char *data = (char*)malloc(file_size+1);
		memset(data,0,file_size+1);
		data[file_size] = '\n';
		memcpy(data,map,file_size);
		printf("file_size:%d \ndata:\n",file_size);
		
		int i;
		for(i = 0;i<file_size;i++)
			putchar(map[i]);
		free(data);
	}while(getchar()!='q'&& getchar());

	munmap(map,map_size);
	return 0;
}

