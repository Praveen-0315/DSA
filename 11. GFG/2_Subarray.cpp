#include<iostream>
#include <vector>
using namespace std; 

vector<int> subarraySum(int arr[], int n, long long s)
    {
        int currentSum, i, j;

    // Pick a starting point
        for (i = 0; i < n; i++) {
            currentSum = arr[i];
            if(currentSum == s) return {i};

            // try all subarrays starting with 'i'
            for (j = i + 1; j < n; j++) {
                if (currentSum == s) {
                    cout << i<< j - 1 << endl;
                    return {1};
                }
                if (currentSum > s || j == n)
                    break;
                currentSum = currentSum + arr[j];
            }
        }

        cout << "No subarray found";
        return {-1};
    }


    int main(){
        int arr[] = {1,2 ,3 ,4, 5};
        int size = sizeof(arr)/sizeof(int );

        subarraySum(arr, size, 6);
        return 0;
    }