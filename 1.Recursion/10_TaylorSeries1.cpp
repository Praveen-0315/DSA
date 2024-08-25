#include <iostream>
using namespace std;

// Taylor Series of e^x using horner's rule
double e(int x, int n){
    static double s=1;
    if(n==0) return s;
    else {
        s=1+x*s/n;
        return e(x,n-1);
    }
}

int main(){
    cout<<e(3,13)<<endl;
    return 0;
}