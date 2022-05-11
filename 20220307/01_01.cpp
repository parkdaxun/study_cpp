#include <iostream>

void swap(int *yo1, int *yo2)
{
	int temp;
	temp = *yo1;
	*yo1 = *yo2;
	*yo2 = temp;
}

void swap(int *yo1, int *yo2)
{
	char temp;
	temp = *yo1;
	*yo1 = *yo2;
	*yo2 = temp;
}

void swap(int *yo1, int *yo2)
{
	double temp;
	temp = *yo1;
	*yo1 = *yo2;
	*yo2 = temp;
}

int main() 
{
	int num1=20, num2=30;
	swap(&num1, &num2);
	std::cout<<num1<<' '<<num2<<' ';
	
	char ch1='A', ch2='Z';
	swap(&ch1, &ch2);
	std::cout<<ch1<<' '<<ch2<<' ';
	
	double db11=1.111, db12=5.555;
	swap(&db11, &db12);
	std::cout<<db11<<' '<<db12<<' ';
}
