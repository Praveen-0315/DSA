#include <iostream>
using namespace std;

int pow(int x, int n){
    if(n==0) return 1;
    int outcome =0;
    outcome = x * pow(x, n-1);
    return outcome;
}
int main(){
    int x,n;
    cout<<"Enter two integer x and n ";
    cin>>x>>n;
    cout<<"x ^ n (i.e. x raise to the power n) is "<<pow(x,n);
    return 0;
}
