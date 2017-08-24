#include <stdio.h>
int cut(int data )
{
  	int count = 0;
  	while(data!=1)
        {
        	count++;
          	if(data%2) //Odd number
                {
                	data = data*3+1;
                  	data /=2;
                }
          	else
                {
                	data /=2;
                }
        }
	
  	return count ;

}
int main(int argc,char *argv[])
{
	int data;
  	scanf("%d",&data);
	printf("%d",cut(data));
  	return 0;
}
