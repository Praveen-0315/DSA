#include <iostream>
using namespace std;

int fun(int n){
    if (n>100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main(){
    cout<<fun(30)<<endl;    //value increases to 101 hence results 91 
    cout<<fun(95)<<endl;    //value increases to 101 hence results 91
    cout<<fun(105)<<endl;   //95
    return 0;
}