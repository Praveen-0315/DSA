#include <iostream>
using namespace std;

int CountZero (int N){
    if(N==0) return 1;
    int count = 0;
    if(N % 10 == 0) count++;
    int a = N/10;
    if(a == 0)
    {
        return count;
    }
    else {
    count+= CountZero(N/10);

    }
    return count;
}

int main(){
    cout<<CountZero(0)<<endl;
    return 0;
}