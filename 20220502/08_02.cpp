#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
	int salary;
public:
	Employee(char* name, int salary): salary(salary)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowEmployeeInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << salary << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[100];
	int empNum;
public:
	EmployeeHandler(): empNum(0) {}
	
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	
	void ShowAllSalaryInfo() const {
		for(int i=0; i<empNum; i++) 
		{
			empList[i]->ShowEmployeeInfo();
		}
	}
	
	void ShowTotalSalary() const {
		int sum = 0;
		for(int i=0; i<empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		
		cout << "ÃÑ ±Þ¿© : " << sum << endl;
	}
	
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
    EmployeeHandler handler;
    handler.AddEmployee(new Employee("KIM", 100));
    handler.AddEmployee(new Employee("LEE", 1000));
    handler.AddEmployee(new Employee("HAN", 10000));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}
