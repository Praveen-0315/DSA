#include <iostream>
using namespace std;

int firstIndex(int arr[], int N, int x){
    if(N==-1) return -1;
    if (arr[0]== x) return 0;

    int ans = firstIndex(arr+1, N-1, x);
    if(ans == -1) return -1;
    return ans + 1;

}

int main(){
    int arr[] = {5, 5, 6, 5, 6};
    cout<<firstIndex(arr, 5, 10)<<endl;
    return 0;
}