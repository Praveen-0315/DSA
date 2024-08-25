#include <iostream>
using namespace std;

int Multiplication(int M, int N){
    int mult = 0;
    if(N==0) return 0;
    return M + Multiplication(M,N-1);
}

int main(){
    cout<<Multiplication(4,0)<<endl;
    return 0;
}