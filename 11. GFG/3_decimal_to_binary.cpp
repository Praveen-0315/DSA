#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int num){
    int ans=0;

    for(int i=0; num>0; i++){
        ans += (num%2) * pow(10, i);
        num /= 2;
    }
    return ans;
}

int BinaryToDecimal(int binaryNum){
    int ans=0;

    for(int i=0; binaryNum>0; i++){
        ans += (binaryNum%10) * pow(2, i);
        binaryNum /= 10;
    }
    return ans;
}

int digits(int num){
    int digit=0;
    while(num>0){
        digit++;
        num /= 10;
    }
    return digit;
}

int reverse(int num){
    int ans=0;
    int digit = digits(num);
    for(int i=digit-1; i>=0; i--){
        ans += (num%10) * pow(10, i);
        num /= 10;
    }
    return ans;
}

long long lcm (long long a, long long b){
        long long maxi = max(a,b);
        for(int i=maxi; i<a*b; i++){
            if(i%a ==0 && i%b==0)
                return i;
        }
        return a*b;
}

int main(){
    
    // cout<<"number of digits in 10: "<<digits(1000)<<endl;
    // cout<<"reverse of 100: "<<reverse(110)<<endl;
    cout<<lcm(14, 8)<<endl;
    
    return 0;
}