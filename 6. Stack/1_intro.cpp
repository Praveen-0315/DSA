#include <iostream>
using namespace std;

class stack {
private:
    int *arr;
    int size;
    int top;

public:
    stack(int size){
        this -> size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element){
        top++;
        arr[top] = element;
    }

    void pop(){
        cout<<"element "<< arr[top]<<" is pop out"<<endl;
        top --;
    }

    void Top(){
        cout<< arr[top]<<endl;
    }
};

int main(){
    stack s(5);

    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);

    s.pop();
    s.Top();
    
    s.pop();
    s.Top();
    
    s.pop();
    s.Top();
    
    s.pop();
    s.Top();

    s.pop();
    s.Top();        // garbage value 
    return 0;
}
