#include <iostream>
#include <math.h>
using namespace std;

bool is_prime_number(unsigned int num);

int main(int argc,char *argv[])
{
	unsigned int big,i;
	cin >>	big;
	int *prime_data = new int[big/2];	
	int prime_num = 0;
	int count =0;
	int tmp;

	for(i = 1;i<=big;i++)
	{
		if( is_prime_number(i) )
		{
			prime_data[prime_num] = i;
		//	cout<<prime_data[prime_num]<<" ";
			prime_num++;
		}

	}

	for(i = 1;i<prime_num -1 ;i++)
	{
		tmp = prime_data[i+1] - prime_data[i];
		if(tmp == 2)
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}

bool is_prime_number(unsigned int num)
{
	if(num == 1)
	{
		return false;
	}
	else if(num == 2 || num == 3)
	{
		return true;
	}else 
	{
		int i = 2;
		for(i;i<=sqrt(num);i++)
		{
			if(num % i == 0)
			return false;
		}
		return true;
	
	}
	



}


