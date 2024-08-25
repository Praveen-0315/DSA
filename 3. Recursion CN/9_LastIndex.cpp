#include <iostream>
using namespace std;

int LastIndex(int arr[], int N, int x){
    if(N==-1) return -1;
    if (arr[N-1]==x) return N-1;
    return LastIndex(arr, N-1, x);

}

int main(){
    int arr[] = {5, 5, 6, 5, 6};
    cout<<LastIndex(arr, 5, 10)<<endl;


}