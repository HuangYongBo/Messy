#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define __IS__MAIN__ 

void reverse(char *str)
{
	if(!str) return;

	char *end = str + strlen(str) -1;
	char *start = str;
	char tmp;

	while(start < end)	
	{
		tmp = *start;
		*start++ = *end;
		*end-- = tmp;	
	}
	
}	



#ifdef __IS__MAIN__
int main(int argc,char *argv[])
{	
	if(argc < 2) return -1;
	char *str = argv[1];
	
#else	
void test(void)
{
	char str[] ="this test function";
#endif
	printf("%s\n",str);
	reverse(str);
	printf("%s\n",str);

#ifdef __IS__MAIN__
	return 0;
#endif
}
