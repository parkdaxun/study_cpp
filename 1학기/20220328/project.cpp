#include<iostream>
#include<string.h> 
#include<stdlib.h>
using namespace std;

typedef struct _student
{
	int std_num;
	string name;
	string birth;
	string phone_number;
} student;

student st[30];
int x=0;

int numberpluse(int n, int o = 1)
{
	return n+o;
}

char * MakeStrAdr(int len)
{
	char * str= new char;
	return str;
}

int put(int &n)
{
	st[n].std_num = n;
	x++;
}

char put(string &a, string &b)
{
	st[x].name = a;
	st[x].birth = b;
}

char put(string &m)
{
	st[x].phone_number = m;
}

void start_scan() 
{	
	int n;
	string a, b, m;
	
	cout<<"학생의 번호는 차례대로 생성 되기 때문에 정해주겠습니다."<<endl;
	n = numberpluse(x); 
	put(n);
	cout<<"학생의 번호는 "<<n<<"번 입니다."<<endl;
	
	cout<<"학생의 이름과 생일을 입력하세요.(띄어쓰기 구분)"<<endl;
	cin>>a>>b;
	put(a, b);
	
	cout<<"학생의 핸드폰 번호를 입력해주세요.(띄어쓰기 X, 숫자 외 입력 X)"<<endl;
	cin>>m;
	put(m);
}

int start_look(int a) 
{
	int number=1;
	
	while(1)
	{
		cout<<"조회하고 싶은 학생의 번호를 입력하세요. (종료 0, 뒤로가기 -1)"<<endl;
		cin>>number;
		
		if(number == -1) return -1;
		if(number == 0) return 0;
	
		if(number > x) 
		{
			cout<<number<<"번의 학생은 존재하지 않습니다. (종료 0)"<<endl;
		}
		
		else 
		{
			int i;
			
			cout<<number<<"번 학생의 이름을 조회하고 싶으면 1, 생일을 조회하고 싶으면 2, 학생의 핸드폰 번호를 조회하고 싶으면 3번을 입력하세요. (종료 0)"<<endl;
			cin>>i;
			
			if(i == 1)
			{
				cout<<number<<"번 학생의 이름은 "<<st[number].name<<"입니다."<<endl;
			}
			
			else if(i == 2)
			{
				cout<<number<<"번 학생의 생일은 "<<st[number].birth<<"입니다."<<endl;
			}
			
			else if(i == 3)
			{
				cout<<number<<"번 학생의 생일은 "<<st[number].phone_number<<"입니다."<<endl;
			} 
		}
	}
	
}  

int main(void)
{
	bool check = false;
	int i;
	char * str=MakeStrAdr(20);
	
	strcpy(str, "안녕하세요! 학생 정보 시스템입니다.");
	cout<<str<<endl;
	
	delete(str);
	
	while(1) 
	{
		cout<<"학생정보 입력을 원하시면 1, 학생정보 조회를 원하시면 0을 눌러주세요."<<endl;
		cin>>check;
		
		if(check == true) 
		{
			cout<<"학생 정보를 입력하시겠습니까? (1/0)"<<endl;
			cin>>check;
			
			if(check == true) start_scan();    
			
			else if(check == false)
			{
				cout<<"입력을 원하시지 않는다면 종료 하겠습니다."<<endl;
				return 0;
			}
		}
		else if(check == false)
		{
			cout<<"학생 정보를 조회하시겠습니까? (1/0)"<<endl;
			cin>>check;
				
			if(check == true) start_look(i);
			
			else if(check == false)
			{
				cout<<"입력을 원하시지 않는다면 종료 하겠습니다."<<endl;
				return 0;
			}
		}
	} 
	ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 
	return 0;
}
