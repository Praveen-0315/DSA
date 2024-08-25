#include<iostream>
using namespace std;

//heirachical 

class Employee
{
private:
    int empId;
    string employeeName;
public:
    Employee(int empId,string employeeName)
    {
        this->empId=empId;
        this->employeeName=employeeName;
    }
    //Accessors
    int getEmpId() {return empId;}
    string getEmpName() {return employeeName;}
};
class FulltimeEmploy: public Employee
{
private: int salary;
public:
    FulltimeEmploy(int empId, string empName, int salary):Employee(empId, empName)
    {
        this->salary=salary;
    }
    int getSalary() {return salary;}
};

class ParttimeEmploy:public Employee
{
private: int wage;
public:
    ParttimeEmploy(int empId, string empName, int wage):Employee(empId, empName)
    {
        this->wage=wage;
    }
    int getWage() {return wage;}
};
int main()
{
    FulltimeEmploy E1 (1,"John",20000);
    ParttimeEmploy E2 (2,"kane", 500);

    cout<<"Salary of "<<E1.getEmpName()<<" is "<<E1.getSalary()<<endl;
    cout<<"Daily Wages of "<<E2.getEmpName()<<" is "<<E2.getWage()<<endl;
    return 0;
}
