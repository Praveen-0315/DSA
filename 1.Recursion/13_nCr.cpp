#include <iostream>
using namespace std;

int fact(int n){
    if(n==0) return 1;
    return fact(n-1)*n;
}
// using factorial recusive function
int nCr(int n, int r){
    int num, den;
    num = fact(n);
    den = fact(r)*fact(n-r);
    return num/den;
}
// using recursion
int NCR(int n, int r){
    if(r==0||n==r) return 1;
    else return NCR(n-1,r-1)+NCR(n-1,r);
}
int main(){
    cout<<NCR(5,2)<<endl;
    return 0;
}