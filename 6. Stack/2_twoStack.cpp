#include <iostream>
using namespace std;

// Two stacks using single array 
class stack {
private:
    int *arr ; 
    int top1;
    int top2;
    int size;

public:
    stack(int s){
        this ->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    //push in stack 1
    void push1(int element){
        if(top2 - top1 >= 1){
            top1++;
            arr[top1] = element;
        }
        else {
            cout<<"Stack is overflow "<<endl;
        }
    }
    //push in stack 2
    void push2(int element){
        if (top2 - top1 >= 1){
            top2--;
            arr[top2] = element;
        }
        else {
            cout<<"Stack is overflow "<<endl;
        }
    }

    // pop from  stack 1
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else 
            return -1;
    }
    // pop from  stack 2
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else 
            return -1;
    }

    int Top1(){
        return arr[top1];
    }

    int Top2(){
        return arr[top2];
    }
};


int main(){
    stack s(10);

    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    s.push1(5);

    s.push2(15);
    s.push2(14);
    s.push2(13);
    s.push2(12);
    s.push2(11);

    //  popping out from stack 1
    cout<<s.Top1()<<endl;
    cout<<s.pop1()<<endl;

    cout<<s.Top1()<<endl;
    cout<<s.pop1()<<endl;
    
    cout<<s.Top1()<<endl;
    cout<<s.pop1()<<endl;
    
    cout<<s.Top1()<<endl;
    cout<<s.pop1()<<endl;
    
    cout<<s.Top1()<<endl;
    cout<<s.pop1()<<endl;


    // poping out from stack 2
    cout<<s.Top2()<<endl;
    cout<<s.pop2()<<endl;

    cout<<s.Top2()<<endl;
    cout<<s.pop2()<<endl;
    
    cout<<s.Top2()<<endl;
    cout<<s.pop2()<<endl;
    
    cout<<s.Top2()<<endl;
    cout<<s.pop2()<<endl;
    
    cout<<s.Top2()<<endl;
    cout<<s.pop2()<<endl;

    return 0;
}
