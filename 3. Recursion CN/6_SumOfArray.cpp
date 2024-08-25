#include <iostream>
using namespace std;

int SumArray(int a[], int size){
    if(size == 0) return 0;

    return a[size] + SumArray(a+1, size-1); 
}

int main(){
    int n;
    int a[n];
    
    cout<<"An Integer N i.e. size of array ";
    cin>>n;
    cout<<"N integers which are elements of the array, separated by spaces";
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Sum of array elements is: "<<SumArray(a,n);
    
    return 0;
}