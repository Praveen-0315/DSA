#include <iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);

    cout<<"Top element of stack is "<<s.top()<<endl;
    s.pop();
    cout<<"Top element of stack is "<<s.top()<<endl;
    s.pop();
    cout<<"Top element of stack is "<<s.top()<<endl;
    s.pop();
    cout<<"Top element of stack is "<<s.top()<<endl;


    return 0;
}