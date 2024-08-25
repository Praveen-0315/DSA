#include <iostream>
using namespace std;
int r=0;
int fun(int n){
    //static int r=0;
    if(n>0){
        r++;
        return fun(n-1) + r;
    }
    return 0;
}
int main(){
    int x=5;
    cout<<fun(x)<<endl;
    return 0;
}