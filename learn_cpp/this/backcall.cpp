#include <iostream>

using namespace std;
class Traveler;

class Police
{
private:
	string answer;
public:
	Police(string answer)
	{
		this->answer = answer;
	}
	void help(Traveler *T);
	void reply()
	{
		cout<<"Police:"<<answer<<endl;
	}
	
};

class Traveler
{
private:
	string question;
public:
	Traveler(string question)
	{
		this->question = question;
	}
	void asked(Police *p)
	{
		cout<<"Traveler:"<<question<<endl;
		p->reply();
	}
};
void Police::help(Traveler *T)
{
	T->asked(this);
}
int main(int argc,char *argv[])
{
	Police p("you can do so");
	Traveler t("How can I do");

	p.help(&t);
	return 0;
}

