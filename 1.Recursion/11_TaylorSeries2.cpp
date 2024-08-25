#include <iostream>
using namespace std;

// taylor's series using iteration
double e(int x, int n){
    double s=1;
    int num=1, den=1;
    for(int i;i<=n;i++){
        num*=x;
        den*=i;
        s+=(double)num/den;
    }
    return s;
}
int main(){
    cout<<e(3,13)<<endl;
    return 0;
}