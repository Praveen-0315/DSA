#include <iostream>
using namespace std;

bool is_sorted(int a[], int size){
    if(size==0 || size==1) return true;

    if(a[0] > a[1]) return false;
    
    bool is_SmallerSorted = is_sorted(a+1, size-1);
    return is_SmallerSorted;
}
int main(){
    int arr[5] = {0, 1, 2, 5, 4};
    cout<<is_sorted(arr, 5);

}