#include <iostream>
using namespace std;

// Using Recursion
int sum(int n){
    if (n==0) return 0;
    else return sum(n-1)+n;
}

// Using Itteration(Loop)
int Isum(int n){
    int s=0;
    for(int i=1;i<=n;i++)
        s += i;
    return s;
}

int main(){
    cout<<Isum(5)<<endl;
    return 0;
}