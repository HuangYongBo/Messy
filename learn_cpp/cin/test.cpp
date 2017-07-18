#include <iostream>
using namespace std;
#include <stdio.h>
int main(int argc,char *argv[])
{
	int num = 10;
	cin >> num;
	cout << num << endl;
	/*输入非数字的内容，num的值会被赋值为0，是因为什么？*/
	
	int arrary[num];
	int i = 0;
#ifdef   CIN_DEBUG
	while(cin >> arrary[i] )
	{
		cout << "arrary["<<i<<"] = "<< arrary[i]<<endl;
		i++;
	}

#else
	cout << scanf("%d",&arrary[i])<<endl;
		cout << "arrary["<<i<<"] = "<< arrary[i]<<endl;
#endif	
	cout << "enter num "<<i << endl;
	return 0;
}
