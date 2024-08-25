#include <iostream>
using namespace std;

void printNum(int x){
    if (x>0){
        printNum(x-1);
        cout<<x<<"  ";
    }
}

int main(){
    int n;
    cout<<"Enter an integer n: ";
    cin>>n;
    cout<<"Numbers from 1 to n: "<<endl;
    printNum(n);
    
    return 0;
    
}