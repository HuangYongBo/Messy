#include <iostream>

using namespace std;
class Point
{
private:
	static int b;
	int x;
	int y;
public:
	Point(int x,int y):x(x),y(y)
	{
		b++;
		cout<<"This is "<<b<<"Point"<<endl;
	}
	
};


int Point::b=0;
int main(int argc ,char*argv[])
{

	int i=0;
	do
	{
		int x = i*3;
		int y = i*4;
		Point a(x,y);
		i++;
	}while(i<100);
	
	return 0;
}
