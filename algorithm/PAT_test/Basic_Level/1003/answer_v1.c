#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 100

int answer_right(char *str)
{
	int len = strlen(str);
	if(len<3)
		return 0;
	int i;
	int j;
	for(i = 0; i< len;i++)
	{
		if(str[i]!='P'&&str[i]!='A'&&str[i]!='T'&&str[i]!='\0')
			return 0;

		if(str[i] == 'P'&&str[i+2]!='T'&&str[i+3]!='T')
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
