#include <stdio.h>
#include <string.h>

int main(int argc,char *argv)
{
	
	char str[81] = {0};
	gets(str);
	printf("%c",str[strlen(str)-1]);

	return 0;
}
