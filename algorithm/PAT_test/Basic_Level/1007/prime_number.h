#ifndef PRIME_NUMBER_H
#define PRIME_NUMBER_H

#include <math.h>

#if  1
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

#endif
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
			count++;
		}
	}

	return count;
	
}

#endif
