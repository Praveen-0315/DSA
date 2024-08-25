#include <iostream>
using namespace std;

class node{
    public:
    
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<< value <<endl;
    }
};
 
void insertAtHead(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}
 
void insertAtTail(node* &head, int val){
    
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    
    node* n=new node(val);
    node* temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=todelete->next;
    head->prev=NULL;
    todelete->next = NULL; 
    delete todelete;
    return ; 
}

void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
    }
    node* temp=head;
    int count=1;
    
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    
    if(temp->next == NULL) {
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
        return ;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

int main()
{
    node* head=NULL;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    insertAtTail(head,40);
    insertAtTail(head,50);
    display(head);
    
    deletion(head,5);
    display(head);
    
    
    deletion(head,3);
    display(head);
    
    deletion(head,2);
    display(head);
    
    deletion(head,1);
    display(head);
    return 0;
}