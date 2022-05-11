#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int num): num(num) {}
	SimpleClass(const SimpleClass& sc): num(sc.num)
	{
		cout << "Called Copy Constructor" << endl;
	}
	void ShowSimpleData() const { cout << num << endl; }
};

SimpleClass SimpleFunc1(SimpleClass sc)
{
	cout << "SimpleFunc1" << endl;
	return sc;
}

SimpleClass& SimpleFunc2(SimpleClass& sc)
{
	cout << "SimpleFunc2" << endl;
	return sc;
}

int main(void)
{
	SimpleClass sc1(100);
	SimpleFunc1(sc1);
	cout << "main called SimpleFunc2" << endl;
	SimpleFunc2(sc1);
	return 0;
}
