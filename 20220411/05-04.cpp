#include<iostream>
using namespace std;

class SimpleClass
{
private :
	int num1;
	int num2;
	
public :
	SimpleClass(int a, int b)
	{
		num1 = a;
		num2 = b;
	}
	
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};
