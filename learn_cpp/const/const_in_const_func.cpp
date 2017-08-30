#include<iostream>

using namespace std;

class Demo
{
private:
	int a;

public:
	Demo(int a=0):a(a){}
	void show()
	{
		cout<<"is't const show:";
		cout<< a<<endl;
	}
	void show()const
	{
		cout<<"is const show:";
		cout<< a<<endl;

	}

	void set(int a)
	{
		this->a = a;

	}
	void set(int a)const
	{
		Demo *p=const_cast<Demo*>(this);
//		this->a = a;//can't do it
		p->a =a ;
	}
};

int main(int argc,char*argv[])
{
	Demo x;
	const Demo y;

	x.set(20);
	x.show();

//	y.set(50); //can't Compile,becasue y is a const value,Demo don't have const function name set
	y.show();	

	return 0;
}
