#include <iostream>
#include <string.h>

using namespace std;
class String
{
private:
	char *p;
	static int i;
public:
	String(const char *p = "")
	{
		cout << this << "String::String(const char *)"<<endl;
		this->p = new char[strlen(p)+1];
		strcpy(this->p,p);
	}
	int get_size(void)
	{
		cout << this << "size is "<<strlen(p)<<endl;
		return strlen(this->p);
	}
	
	char *c_str(void)
	{
		return this->p;
	}

	String(const String &tmp)
	{
		cout << this << "String::String(const String &tmp"<<endl;
		this->p = new char[strlen(tmp.p)+1];
		strcpy(this->p,tmp.p);
		i++;
	}
	~String()
	{
		cout << this << "String::~String ()"<<endl;
		if(p)
		{
			delete []p;
			p = NULL;
	
		}
	}

	String func(String a)
	{
		return a;
	}

	String  func2(String &a)
	{
		return a;
	}

	String & func3(String &a)
	{
		return a;
	}
	String  func4(String a)
	{
		String b = a;
		return b;
	}
	
	


};
int String::i =0;


int main(int argc,char *argv[])
{
#if 0
	
	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a ;
	cout << " c = " << c;
	cout << " b = " << b;
	cout << " a = " << a;
	cout << endl;
	String s("hello");
	String h(s);

	s.get_size();
	h.get_size();
#endif 
	String s("hello");

#if DEBUG1
	s.func(s);
#elif DEBUG2
	s.func2(s);

#elif DEBUG3
	s.func3(s);
#elif DEBUG4
	s.func4(s);
#endif
	return 0;
}
