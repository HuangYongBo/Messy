#include<stdio.h>
char *str[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int add_string_data(char *str)
{
	int sum = 0;
  	while(*str!='\0')
        {
          	sum += *str - '0';
        	str++;
        }
  	return sum;
}

void show_data_to_Chinese(int data,int time)
{
 		 
   
	if(data/10)
	{
		show_data_to_Chinese(data/10,time+1);
	}

    	printf("%s",str[data%10]);
	if(time == 1)
	{
		printf("\n");
	}
	else
	{
		printf(" ");
	}
	return;
   
	
}

int main(int argc,char *argv[])
{
  	char num_str[101] = {0};
        int sum = 0;
  	scanf("%s",num_str);
  	sum = add_string_data(num_str);
	printf("%d",sum);
  	show_data_to_Chinese(sum,1);
	return 0;
}


