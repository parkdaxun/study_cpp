#include<iostream>
#include<cstring>
using namespace std;

class Person{
	private:
		char* name; //그냥 포인터 같아 보이지만 배열 포인터 
	public:
		Person(char* name)
		{
			this->name = new char[strlen(name)+1];
			strcpy(this->name, name);
		}
		~Person()
		{
			delete[] name; //해제 시켜줄때 배열로 해체하기 
		}
		
		void WhatYourName() const
		{
			cout << "My name is " << name << endl;
		}
};
class UnivStudent : public Person{
	private :
		char* subject;
	public :
		
		UnivStudent(char* name, char* subject) : Person(name)
		{
			this->subject = new char[strlen(subject)+1];
			strcpy(this->subject, subject);
		}
		
		~UnivStudent() 
		{
			delete[] subject;
		}
		
		void WhoAreYou() const
		{
			WhatYourName();
			cout << "My major is " << subject << endl;
		}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Park", "Computer Engineering");
	st2.WhoAreYou();
	return 0;
}
