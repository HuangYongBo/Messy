#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>
struct port
{
	int x;
	int y;
	int data;
};

bool is_only(int *data,int len,int num)
{
	int i;
	int tmp = 0;
	for(i = 0; i < len; i++)
	{
		if(*(data+i) == num)
			tmp++;
	}
	return (tmp == 1)?(1):(0);
}
int main(int argc ,char *argv[])
{

	int M,N,TOL;
	scanf("%d",&M);
	scanf("%d",&N);
	scanf("%d",&TOL);
	int w = M + 1;
	int h = N + 1;
	int array_size = (M+1)*(N+1);
	int data_size = M * N;
	int *data = malloc(array_size);
	struct port *only = malloc(data_size*sizeof(struct port));
	int only_count = 0;
	int i,j;
	
	memset(data,'0',array_size);
	memset(only,'0',data_size*sizeof(struct port));
	for(i = 1 ;i <= N;i++)
	{
		for(j = 1;j <= M;j++)
		{
			scanf("%d",(data + i*w + j));
		}
	}
	for(i = 1 ;i <= N;i++)
	{
		for(j = 1;j <= M;j++)
		{
			printf("%-5d",*(data+i*w+j));
			if(is_only(data,array_size,*(data+i*w+j)))	
			{
				only[only_count].data = *(data + i*w + j);
				only[only_count].x = j;
				only[only_count].y = i;
				only_count++;
			//	printf("%-10d,%-10d,%-10d",only[only_count].x,only[only_count].y,only[only_count].data);
			}
			
		}
		printf("\n");
	}

	for(i=0;i<only_count;i++)
	{
		printf("%-10d",only[i].data);
	}
	return 0;

}



