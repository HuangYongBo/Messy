#include<iostream>
#include<stdio.h>
using namespace std;



class Father
{
public :
//	Father();
	virtual void func_fat(void)= 0;

	void func_1(void);	
};
/*Father::Father(void)
{}*/
void Father::func_fat(void)
{
	printf("hellodff world\n");
}
void  Father:: func_1(void)
{
	func_fat();
}
class AA: public Father
{
private:
public:
	AA(void);		
	void func_fat(void);

};

AA::AA(void)
{

}
void AA::func_fat(void)
{
	printf("hello world\n");
}
int main(int argc,char *argv[])
{
//	Father faff =Father();
//	faff.func_1();

	AA ccc;// = new AA(void);
	ccc.func_fat();

	return 0;
}
