#include <iostream>
using namespace std;

void merge(int arr[], int l, int r , int m){
    
    int i = l, j = m+1;
    int *temp = new int[r+1];
    int k = l;
    while(i<=m and j<=r)

    {
         if(arr[i]>arr[j])
         {
             temp[k++] = arr[j++];
         }
         else{
             temp[k++] = arr[i++];
         }
    }

    while(i<=m)
    {
        temp[k++] = arr[i++];
    }
    while(j<=r)
    {
        temp[k++] = arr[j++];
    }

    for(int i = l; i<=r; i++)
    {
        arr[i] = temp[i];
    }
    
    
}

void  mergeSort (int arr[], int l, int r ){
    // base condition 
    if( l <r ) {

        int m = (l+r)/2;

        // sorting left array
        mergeSort(arr,  l, m);
        // sorting right array
        mergeSort(arr, m+1 , r);

        // merge left and right array
        merge(arr, l, r , m);
    }
}

int main(){
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<"  ";
}