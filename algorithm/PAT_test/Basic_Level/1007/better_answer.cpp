#include <iostream>
#include "prime_number.h"

using namespace std;

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
