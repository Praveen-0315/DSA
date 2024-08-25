#include<iostream>
using namespace std;

int NumDigits (int n){
    int i=1;
    if(n/10>0){
        n /= 10;
        i++;
        NumDigits(n-1);

    }
    return i;
}
int main(){
    int n;
    cout<<"Enter an Integer n: ";
    cin>>n;
    cout<<"Count of digits: "<<NumDigits(n)<<endl;
    return 0;

}