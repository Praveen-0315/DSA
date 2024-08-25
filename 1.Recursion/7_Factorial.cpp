#include <iostream>
using namespace std;

// Using Recursion
int fact(int n){
    if(n==1) return 1;
    else return fact(n-1)*n;
}

// Using Iteration
int Ifact(int n){
    int fac=1;
    for(int i=1;i<=n;i++)
        fac *= i;
    return fac;
}
int main(){
    cout<<Ifact(5)<<endl;
    return 0;
}