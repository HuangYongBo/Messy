#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int num = 10;
	cin >> num;
	cout << num << endl;
	/*输入非数字的内容，num的值会被赋值为0，是因为什么？*/
	return 0;
}
