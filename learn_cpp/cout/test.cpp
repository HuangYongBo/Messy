#include <iostream>

//using namespace std::cout;
using std::cout;


void test()
{
	static int num = 10;
	num++;
	cout << num << std::endl;
		
}
int main(int argc,char *argv[])
{
	int a = 10;
	{
		int a =  20;
		cout << a << std::endl;
	}
	test();
	test();
	//cout << num << std::endl;
	
	cout << /* " */" /* "/*  "*/;
	return 0;

}
