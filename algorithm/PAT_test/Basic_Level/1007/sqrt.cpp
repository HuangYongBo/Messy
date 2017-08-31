#include <iostream>

#include <math.h>

using namespace std;
bool is_prime_number(unsigned int num);

int main(int argc,char*argv[])
{

	int num ;
	cin >> num;
	cout << is_prime_number(num) << endl;



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
		for(i;i<sqrt(num);i++)
		{
			if(num % i == 0)
			return false;
		}
		return true;
	
	}
	



}
