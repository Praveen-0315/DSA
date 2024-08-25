/*
------------------------------- 3 patterns in recursion ------------------------------------

1. Print All 
2. Print one
3. count
*/

#include <iostream>
#include<vector>
using namespace std;

void printAll(int i, int arr[], int s, vector<int> &ds, int sum, int n){
    // base case
    if(i==n){
        if(s == sum){
            for(int it=0; i<ds.size(); i++)
                cout<<ds[it]<<" ";
            cout<<endl;
        }
        return;
    }
    // Picks
    ds.push_back(arr[i]);
    s += arr[i];
    printAll(i+1, arr, s, ds, sum, n);
    
    // Not Picks
    ds.pop_back();
    s -= arr[i];
    printAll(i+1, arr, s, ds, sum, n);
}

bool printOne(int i, int arr[], int s, vector<int> ds, int sum, int n){
    // base case
    if( i == n){
        if(s == sum){
            for(int it=0; i<ds.size(); i++)
                cout<<ds[it]<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    // Picks 
    ds.push_back(arr[i]);
    s += arr[i];
    if(printOne(i+1, arr, s, ds, sum, n)) 
        return true;
    // Not picks
    ds.pop_back();
    s -= arr[i];
    if(printOne(i+1, arr,  s, ds, sum, n)) 
        return true;
    return false;
}

int Count(int i, int arr[], int s, vector<int> ds, int sum, int n){
    // Base case
    if( i == n){
        if(s == sum)
            return 1;
        return 0;
    }
    // Picks
    ds.push_back(arr[i]);
    s += arr[i];
    int left = Count(i+1, arr,  s, ds,  sum, n);
    // Not picks
    ds.pop_back();
    s -= arr[i];
    int right = Count(i+1, arr, s, ds, sum, n); 
    return right + left;
}




int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/ sizeof(int);
    vector<int> ds;
    int sum = 2;
    cout<<Count(0, arr, 0, ds, sum, n);
    return 0;
}
