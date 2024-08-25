#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first=NULL;
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int count(Node *p){
    int x=0;
    while(p){
        x++;
        p = p->next;
    }
    return x;
}

void display(Node *p){
    while(p){
        cout<<p->data<<"  ";
        p = p->next;
    }
    cout<<endl;
}

void insert(Node *p, int index, int x){
    Node *t = new Node;
    
    if(index<0 || index > count(p)){
        return;
    }
    t->data = x;

    if(index == 0){
        t->next = first;
        first = t;
    }
    else {
        for(int i = 0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        
    }

}

void duplicate(Node *first){
    Node *q = first->next;
    Node *p = first;

    while(q) {
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main(){
    int arr[] = {2, 3, 3, 4, 5, 5, 8};
    create(arr, 7);

    cout<<"Linked list  with duplicates "<<endl;
    display(first);
    cout<<"Linked list without duplicates "<<endl;
    duplicate(first);
    display(first);
}