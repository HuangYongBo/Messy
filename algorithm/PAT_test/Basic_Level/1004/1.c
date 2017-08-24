#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[11];
	char num[11];
	int socre;
};
int main(int argc,char * argv[])
{
	int num;
	scanf("%d",&num);
	struct student *students = malloc(num*sizeof(struct student));
	int i;
	int max = 0;
	int min = 0;
	for(i = 0;i<num;i++)
	{
		scanf("%s %s %d",students[i].name,students[i].num,&(students[i].socre));	
		if(students[max].socre <= students[i].socre)
			max = i;
		if(students[min].socre >= students[i].socre)
			min = i;
		
	}
	printf("%d %d\n",max,min);
	printf("%s %s\n",students[max].name,students[max].num);
	printf("%s %s\n",students[min].name,students[min].num);
	return 0;
}
