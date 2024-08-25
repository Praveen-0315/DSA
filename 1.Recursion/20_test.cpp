#include <iostream>
using namespace std;

void update(int *a, int *b){
    *a= *a + *b;
    *b= *a-2*(*b);
    if (*b<0) *b *= -1;

}
int main(){
    int a=9,b=5;
    update(&a,&b);
    cout<<a<<endl<<b<<endl;
    return 0;
}