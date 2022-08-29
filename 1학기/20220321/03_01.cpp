#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	
	const int *po = &num; //포인터 변수 선언 
	
	const int *(&num2) = po; //참조자 선언 
	
	cout<<*num2<<endl; //num에 저장된 값 출력 
}
