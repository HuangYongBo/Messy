#include<iostream>
using namespace std;

class Counter{
private:
	int n;
public:
	Counter(int n = 0)
	{
		this->n = n;
	}
//	Counter & inc()
	Counter  inc()
	{
		n++;
		cout << "tset"<< n << endl;

		return *this;
	}
	
	void show()
	{
		cout << n << endl;
	}

};

int main(int argc,char *argv[])
{
	int n = 1;	
	Counter c(n);
	c.show();
	
	c.inc().inc().inc();
	c.show();
	
}
