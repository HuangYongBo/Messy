#include <iostream>

using namespace std;
int cut(int data ,int *array);

int main(int argc,char *argv[])
{
	int num;
	cin >> num;
	int *data = new int[num];
	int *center = new int[num];
	int (*p)[100] = new int[num][100];
	int i,j;
	int count=0;

	
	for(i = 0;i<num;i++)
	{
		cin>>data[i];
//		cout<<data[i];
		p[i][0] = cut(data[i],&p[i][1]);
	}
	for(i = 0;i<num;i++)
	{
//		find_num(num[i],data
		
		for(j = 0;j<p[i][0]+1;j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<endl;

	}
	return 0;
}
int cut(int data ,int *array)
{
  	int count = 0;
	
  	while(data!=1)
        {
		*array = data;
        	count++;
		array++;
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


bool find_num(int data,int *array)
{
	int *p = array;
	int i;
	for(i = 1;i < array[0]+1;i++)
	{
		if(data == array[i])
			return false;

	}

	return  true;
}
