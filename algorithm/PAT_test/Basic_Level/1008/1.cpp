#include <iostream>

using namespace std;


void getdata(int *p,int amount)
{
	//int *p = new int[amount];
	int i;
	for(i = 0;i < amount;i++)
	{

		cin>>p[i];
	}
	
	


}
void move_array(int *array,int len,int M)
{
	int count = 0;
	int i ,j=-1 ,k;
	int tmp1,tmp2;
	if(M == len) return ;
	if(M>len) M=M-len;
	
	do
	{
		j++;
		i=j;	
		tmp1 = array[i];
		
		do
		{	
			k = (i+M >=len)?(i+M-len):(i+M);
			tmp2 = array[k];
			array[k] = tmp1;
			tmp1 = tmp2;
			
			i +=M;
			if(i >= len)
				i -= len;
	//		cout<<i<<"|";
			count++;
		}while(i != j);
	}while(count != len);



}
void show_array(int *array,int len)
{
	int i;
	for(i = 0;i < len - 1;i++)
	{
		cout << array[i] << " ";
	}
		cout << array[i] << endl;

}

int main(int argc,char*argv[])
{
	int amount;
	int step;//move 
	
	cin >> amount >> step;
	int *data = new int[100];

	getdata(data,amount);	

	

	move_array(data,amount,step);
	
	show_array(data,amount);
		

	


	delete[] data ;
	return 0;
}
