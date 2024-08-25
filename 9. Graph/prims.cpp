// Minimum Cost spanning tree

#include <iostream>
#define I INT_MAX
using namespace std;

int cost[8][8] = {{I, I, I, I, I, I, I, I},
                  {I, I, 25, I, I, I, 5, I},
                  {I, 25, I, 9, I, I, I, 6},
                  {I, I, 9, I, 10, I, I, I},
                  {I, I, I, 10, I, 12, I, 11},
                  {I, I, I, I, 12, I, 18, 16},
                  {I, 5, I, I, I, 18, I, I},
                  {I, I, 6, I, 11, 16, I, I}};
int near[8] = {I, I, I, I, I, I, I, I};
int ans[2][6];

int main(){
    int min = I, n=7, vertex1, vertex2;
    // finding minimum cost edge in graph
    for(int i = 1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                vertex1 = i;
                vertex2 = j;
            }
        }
    }
    // pushing value of edges with minimum cost in ans 
    ans[0][0] = vertex1;
    ans[1][0] = vertex2;
    near[vertex1] = near[vertex2] = 0;      // marking vertex1 and vertex2 as visited

    // NOW repeating for other elements 

    // updating near[] .... i is near to vertex1 or vertex2
    for (int i= 1; i <= n; i++){
        if(near[i] != 0 ){
            if(cost[i][vertex1] < cost[i][vertex2])
                near[i] = vertex1;
            else
                near[i] = vertex2;
        }
    }
    // checking for minimum cost edge in near[]
    for(int i=1; i < n-1; i++){
        min = I;
        int k;
        for(int j=1; j<= n; j++){
            if(near[j]!= 0 && cost[j][near[j]]<min){
                k = j;
                min = cost[j][near[j]];
            }
        }
        ans[0][i] = k;
        ans[1][i] = near[k];
        //updating near[]
        near[k] =0;
        for(int j=1; j<= n; j++){
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }

    // displaying
    for(int i=0; i< n-1; i++){
        cout<<"(" << ans[0][i] << "," << ans[1][i] << ")"<<endl;
    }



}
