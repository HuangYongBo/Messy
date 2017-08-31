#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int num;
	int *data = new int[3];
	int i,j;

	cin >> num;
	for(i = 0;i<3;i++)
	{
		if(num == 0) break;
		data[i] = num%10;
		num /=10;

	}

	for(i = 2;i >= 0;i--)
	{
		for(j=1 ;j <= data[i];j++)
		{
			switch(i)
			{
				case 2:
					cout<<"B";
					break;
				case 1:
					cout<<"S";
					break;
				case 0:
					cout<<j;
					break;
	
			}

		}

	}
	
	
	
	return 0;
}
