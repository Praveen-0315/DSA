#include <iostream>
using namespace std;

bool IsPresent (int arr[], int size, int key){
    if(size==-1) return false;
    if(arr[0]==key) return true;
    return IsPresent(arr+1, size-1, key);
}

int main(){
    int arr[] = {1, 2, 3, 4 ,5};
    cout<<IsPresent(arr, 5, 3);
    return 0;
}