/* class employee       ---
    name, age,  salary     -----> class manager, department (data), member fun
    print_salary()      ---


*/

#include<iostream>
#include<string.h>
using namespace std;

class employee{
protected:
    string name;
    int age, salary;
public:
    void print_salary(){
        cout<<"Salary is: "<<salary<<endl;
    }
    

};

class manager : public employee{
string department;
public:
    void set(){
        cout<<"Enter the Name ";
        cin>>name;
        cout<<"Enter the age";
        cin>>age;
        cout<<"Enter salary";
        cin>>salary;
    }
    void display(){
        cout<<"Name: "<<name<<"\n Age: "<<age<<"\n salary: "<<salary;
    }
};
class team : public employee{
string specialisation;
public:
    void set(){
        cout<<"Enter the Name ";
        cin>>name;
        cout<<"Enter the age ";
        cin>>age;
        cout<<"Enter salary ";
        cin>>salary;
    }
    void display(){
        cout<<"Name: "<<name<<"\n Age: "<<age<<"\n salary: "<<salary<<endl;
    }
};

int main(){
    team t;
    manager m;
    t.set();
    m.set();
    cout<<"\t team"<<endl;
    t.display();
    cout<<"\t Manager"<<endl;
    m.display();

    return 0;
}