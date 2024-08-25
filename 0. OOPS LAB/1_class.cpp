//WAP to design a calculator using classes

#include <iostream>
using namespace std;

class interest{
    private:
    int a,b;
    public:
    void input();
    void add();
    void diff();
    void mul();
    void division();
}c;

void interest::input(){
    a=0;b=0;
    cout<<"Enter nos: ";
    cin>>a>>b;
}
void interest::add(){
    cout<<a+b<<endl;
}
void interest::diff(){
    cout<<a-b<<endl;;
}
void interest::mul(){
    cout<<a*b<<endl;
}
void interest::division(){
    cout<<a/b<<endl;
}

int main(){
    int ch;

    cout<<"1.Add"<<endl;
    cout<<"2.Subtracy"<<endl;
    cout<<"3.Multiply"<<endl;
    cout<<"4.Divide"<<endl;

    do{
       
        cout<<"Enter choice: ";
        cin>>ch;
        c.input();

        switch (ch){
            case 1: 
            c.add();
            break;
            
            case 2:
            c.diff();
            break;

            case 3:
            c.mul();
            break;

            case 4:
            c.division();
            break;

            default:
            break;
        }
        
    }while(ch!=0);
    
    return 0;
}