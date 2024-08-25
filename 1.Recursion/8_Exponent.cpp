#include <iostream>
using namespace std;

// Using Recursion
int expo(int m, int n){
    if(m==0) return 0;
    if(n==0) return 1;
    else return expo(m, n-1)*m;
}

// Using Iteration
int Iexpo(int m, int n){
    int e = 1;
    for(int i=1;i<=n;i++)
        e *= m;
    return e;
}

int main(){
    cout<<Iexpo(4,3)<<endl;
    return 0;
}