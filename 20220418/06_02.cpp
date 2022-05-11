#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int n): num(n)
	{
		cout << "°´Ã¼ »ý¼º" << endl;
	}
	SimpleClass& Adder(int n)
	{
		num += n;
		return *this;
	}
	SimpleClass& ShowSimpleData()
	{ 
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SimpleClass sc(1);
	SimpleClass& ref = sc.Adder(1);
	
	sc.ShowSimpleData();
	ref.Adder(1).ShowSimpleData().Adder(1);
	sc.Adder(1).ShowSimpleData().Adder(1);
	ref.ShowSimpleData();
	
	return 0;
}
