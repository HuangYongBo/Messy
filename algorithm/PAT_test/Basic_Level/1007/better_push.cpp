#include <iostream>
#include<math.h>

using namespace std;

unsigned int get_prime_number(unsigned int num,int *array);
int main(int argc,char*argv[])
{
	int num;
	int i,ret;
	int count = 0;
	cin >> num;

	int *prime = new int[(num+1)/2];

	ret = get_prime_number(num,prime);

	for(i = ret -1;i>0;i--)
	{
		if(prime[i] - prime[i-1] == 2)
			count++;
	}

	cout << count<<endl;
	return 0;
}
unsigned int get_prime_number(unsigned int num,int *array)
{
	bool *p = new bool[num+1];
	unsigned int i,j;	
	unsigned  tmp;
	unsigned int count = 0;
	for(i = 3;i <= num ;i++)
	{
		if(i%2)
			p[i] = true;
		else
			p[i] = false;
	}
	p[0] = false;
	p[1] = false;
	p[2] = true;

	tmp = sqrt(num) + 1;
	for(i = 2;i<= tmp;i++)
	{
		if(p[i])
		{
			for(j = i+i;j<= num; j+=i)
			{
				p[j] = false;
			}
		}
	
	}
	for(i = 0;i<=num;i++)
	{
		if(p[i])
		{
			array[count] = i;
//			cout<<array[count]<<" ";
			count++;
		}
	}

	return count;
}	
