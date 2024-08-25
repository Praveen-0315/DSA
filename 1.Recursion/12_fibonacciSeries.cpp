#include <iostream>
using namespace std;

//using iteration
int fib(int x){
    int t0=0, t1=1, s=0, i;
    for(i=2;i<=x; i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

//using recursion
int rfib(int x){
    if(x<=1) return x;
    else return rfib(x-2)+rfib(x-1);    
}

int F[10];
//using memoization
int mfib(int x){
    if(x<=1){
        F[x]=x;
        return x;
    }
    else{
        if(F[x-2]==-1)
            F[x-2]=mfib(x-2);
        if(F[x-1]==-1)
            F[x-1]=mfib(x-1);
        F[x] = F[x-2]+F[x-1];
        return F[x];
    }
}
int main(){
    for(int i=0;i<=10;i++){
        F[i]=-1;
    }
    cout<<mfib(5)<<endl;
    return 0;
}