#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=1; i<n; i++){
    // for round 1 to n
        bool swaping  = false;
        for (int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaping  = true;
            }
        }
        if(swaping == false) break;
    }
}


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    bubbleSort(arr, 5);
    for(int i=0; i<5; i++) cout<<arr[i]<<"  ";
    return 0;
}