#include<iostream>
using namespace std;

class car{
protected:
    int wheel = 4;
public:
    void start() {
        cout<<"car is starting. "<<endl;
    }
};

class jaguar : public car{
    string companyName = "jaguar";
    int price = 4500000;
public:
    void getCom() {
        cout<< companyName<<endl;
    }
    void getprice() {
        cout<< price<<endl;
    }
};

int main(){
    jaguar j;
    j.getCom();
    j.getprice();
    j.start();

    return 0;
}