#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter no. of rows and columns of array: ";
    cin>>n>>m;
    int **p = new int*[n];
    for(int i=0; i<n; i++){
        p[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> p[i][j];
        }
    }

    //deallocation 
    for(int i=0; i<n; i++){
        delete [] p[i];
    }
    delete [] p;
    return 0;

}