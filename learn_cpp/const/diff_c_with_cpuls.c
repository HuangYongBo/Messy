#include <stdio.h>

int main(int argc,char *argv[])
{
	volatile const int a = 1;
	
	int *p = (int*)&a;
	*p = 100;
	printf("%d\n",a);
	
	return 0;
}
