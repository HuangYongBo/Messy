#include <iostream>


using namespace std;
int cut(int data);
int show(int *array,int len);
void bubble_sort(int *array,int len);
  
int *array = new int[400];

int main(int argc,char *argv[])
{
	int num;
	int *data = new int[100];
	int *key = new int[100];
	int i,j,count=0;	

	cin >> num;
	for(i = 0 ;i< num;i++)
	{
		cin >> data[i];
		cut(data[i]);	
	}
	
	for(i = 0;i < num;i++)
	{
		if(array[data[i]] != 1)
		{
			key[count] = data[i];
			//cout<<key[count]<<endl;
			count++;
		}

	}
	
	bubble_sort(key,count);	
	show(key,count);	

	
	return 0;
}
int show(int *array,int len)
{
	int i;
	for(i = 0;i < len-1;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<array[i]<<endl;
}

int cut(int data)
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
		array[data] = 1;
        }
	
  	return count ;

}

void bubble_sort(int *array,int len)
{
	int i,j;
	int tmp;

	for(i = 0 ;i<len-1;i++)
	{
		for(j = 0 ; j < len -i -1;j++)
		{
			if(array[j] <= array[j+1])
			{
				tmp = array[j];
			//	std::cout<<"tmp:"<<tmp<<std::endl;
				array[j] = array[j+1];
				array[j+1] = tmp;
				
			}
		}

	}


}


