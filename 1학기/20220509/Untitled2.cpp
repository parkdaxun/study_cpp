#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100];
public:
    Employee(char* name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const {return 0;}
    vitual void ShowSalaryInfo() const {}
};

class FullTimeWorker: public Employee
{
private:
    int salary;
public:
    FullTimeWorker(char* name, int salary)
        : Employee(name), salary(salary) {}
    virtual int GetPay() const
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i = 0 ; i < empNum ; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0 ;
        for(int i = 0 ; i < empNum ; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for(int i = 0 ; i < empNum ; i++)
            delete empList[i];
    }
};

int main(void)
{
    EmployeeHandler handler;

    handler.AddEmployee(new FullTimeWorker("KIM", 1000));
    handler.AddEmployee(new FullTimeWorker("LEE", 1500));

    PartTimeWorker* ptw = new PartTimeWorker("JUNG", 100);
    ptw->AddWorkTime(25);
    handler.AddEmployee(ptw);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    
    return 0;
}
