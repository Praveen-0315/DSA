#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<< value <<endl;
    }
};

void insert(Node* &head, int position, int data){
    Node *NodetoInsert = new Node(data);
    Node *current = head;
    
    //List is empty
    if(head == NULL) {
        head = NodetoInsert;
        return ;
    }

    // inserting at head
    if(position == 1){
        NodetoInsert -> next = head;
        head->prev = NodetoInsert;
        head = NodetoInsert;
        return;
    }
    
    //traversing to the desired Node
    int count = 1;
    while(count < position-1){
        current = current->next;
        count++;
    }

    //inserting at last
    if(current->next == NULL) {
        current->next = NodetoInsert;
        NodetoInsert->prev = current;
        return;
    }

    //inserting at mid 
    NodetoInsert->next = current->next;
    current->next->prev = NodetoInsert;
    current->next = NodetoInsert;
    NodetoInsert->prev = current;
}

void print(Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void deleteNode(Node* &head, int position){
    Node *temp = head;
    if(position ==1){
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int count = 1;
    while(count < position){
        temp = temp->next;
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

int main(){
    Node *head = NULL;

    insert(head, 1, 15);
    insert(head, 1, 16);
    insert(head, 1, 20);
    insert(head, 1, 26);
    print(head);
    // 26 20 16 15

    insert(head, 5, 100);
    //print(head);
    // 26 20 16 15 100

    deleteNode(head, 1);
    print(head);
    // memory is free for node with data 26
    //20 16 15 100 

    deleteNode(head, 4);
    print(head);

    return 0;
}