#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor 
    Node(int data ){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor 
    ~Node() {
        int value = this -> data;
        //memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data "<< value<<endl;
    }

};

void insert (Node * &head, int position ,int data){
    Node *NodeToinsert = new Node(data);
    Node *current = head;

    //empty list
    if(head == NULL){
        head = NodeToinsert;
        return ;
    }
    
    //inserting at head
    if(position == 1){
        NodeToinsert -> next = head;
        head = NodeToinsert;
        return ;
    }

    //inserting at mid or last
    int count = 1;
    while(count < position-1){
        current = current->next;
        count++;
    }
    NodeToinsert -> next = current->next;
    current->next = NodeToinsert;
}

void print(Node * &head){
    Node* temp = head;
    while(temp){
        cout<<temp -> data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(Node* &head, int position){
    //deleting first node
    if(position == 1) {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    else // last or middle nodes 
    {
        Node *current = head;
        Node *prev = NULL;
        int count = 1;
        while(count < position) {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        current -> next = NULL;
        delete current;
    }

}

int main(){
    //Node *node1 = new Node(10);

    Node *head = NULL;

    insert(head, 1, 12);
    insert(head, 2, 15);
    insert(head, 2, 19);
    print(head);

    deleteNode(head, 3);
    print(head);

    return 0;
}
