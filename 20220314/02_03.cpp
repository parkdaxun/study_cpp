#include <iostream>
using namespace std;

void SwapPointer(int *(&val1), int *(&val2))
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

int main(void)
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	
	SwapPointer(ptr1, ptr2);
}

