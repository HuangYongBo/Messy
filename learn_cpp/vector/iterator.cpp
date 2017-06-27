#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char *argv[])
{
	vector <string> test;
	vector <string>:: const_iterator iter;
	iter = test.begin();	
	test.push_back("my");
	test.push_back("and");
	test.push_back("you");

	cout << test.size() <<endl;
	int i;
	for(i = 0 ; i< test.size(); i++)
	{
		cout << test[i] << " ";
			
	}
		cout << endl;

	return 0;
}
