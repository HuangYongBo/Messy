#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 100

int answer_right(char *str)
{
	int len = strlen(str);
	if(len < 3) return 0;
	int i;
	int p_index = 0;
	int p_count = 0;
	int t_index =0;
	int t_count = 0;
	char flag = 0;
	for(i = 0; i< len;i++)
	{
		if(str[i] == 'P')
		{
			flag |= 1<<0;
			p_index = i;
			p_count++;
			if(p_count > 1) return 0;
		}else if(str[i] == 'A')
		{
			flag |= 1<<1;
		}else if(str[i] == 'T')
		{
			flag |= 1<<2;
			t_index = i;
			t_count++;
			if(t_count > 1) return 0;
		}else 
		{
			return 0;
		}
		
	}
	if(0x7!=flag || !((len-t_index-1)-p_index == (t_index-p_index-2)*p_index))
	{
		return 0;
	}
	return 1;

}
int main(int argc,char *argv[])
{
	unsigned int n;
	scanf("%d",&n);
	char *p[n];
	int i=0;
	for(;i<n;i++)
	{
		p[i] = malloc(STR_SIZE);
		memset(p[i],0,STR_SIZE);
		scanf("%s",p[i]);
		//printf("%s\n",p[i]);
	}
	
	
	for(i=0;i<n;i++)
	{
		printf("%s\n",answer_right(p[i])?"YES":"NO");

		free(p[i]);
	}

	return 0;
}
