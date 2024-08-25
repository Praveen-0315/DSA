#include <iostream>
using namespace std;

void Insertionsort(int arr[], int size){
    for(int i =1; i< size; i++){
        int temp = arr[i];

        int j=i-1;
        for(; j>0; j-- ){
            if(arr[j]>temp){
                arr[j+1];
            }
            else break;
        }
    }
}