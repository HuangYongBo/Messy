#include <iostream>
using namespace std;

class Staff
{
private:
	string name;
	int num;
	int old;
	char sex;
	int level;
	float income;
	Staff *pre;
	Staff *next;
	static Staff *head;
public:
	Staff(string name,int num,int old,char sex,int level,int income):
		name(name),num(num),sex(sex),level(level),income(income)
	{
		this->pre = NULL;
		this->next = NULL;
		if(head != NULL)
		{
			this->pre = head;
			head->next = this;
		}

		head = this;	
	}
	~Staff();

	static void show();

};

Staff::~Staff()
{	
/*	if(this == head)
	{
		this->pre->next = NULL;
	}else if(head != NULL)
	{
		this->pre->next = this->next;
		this->next->pre = this->pre;

		this->pre = NULL;
		this->next = NULL;

	}
*/		head = this->pre;

}
void Staff::show()
{
	Staff *tmp;
	tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->name<<endl;

		tmp = tmp->pre;

	}

	cout<<"show end"<<endl;
}
Staff* Staff::head=NULL;
int main(int argc,char *argv[])
{
	Staff s1("jack",4,4,4,1,9000);
	Staff s2("jac",3,3,3,2,9000);
	s1.show();

	Staff s3("ja",2,2,2,3,9000);

	Staff::show();
	Staff s4("j",1,1,1,4,9000);
	s4.show();
	return 0;
}
