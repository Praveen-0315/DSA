#include <iostream>
#include <math.h>
using namespace std;

float SumOf_GP(int k){
    
    if (k==0) return 1;
    float a = SumOf_GP(k-1);
    float answer = 1/(float)pow(2,k) + a;
    return answer;
    
   /*
   // base case
    if (k == 0)
        return 1;
 
    // calculate the sum each time
    float ans = 1 / (float)pow(3, k) + SumOf_GP(k - 1);
 
    // return final answer
    return ans;
    */
}

int main(){
    cout<<SumOf_GP(3)<<endl;
    return 0;
}