#include <iostream>
using namespace std;

class Node{
public:
    Node *right;
    Node *left;
    int data;
    int height;

    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }

    
};
int getheight(Node *root){
        if(root == NULL)  return 0;
        return root->height;
    }

int getbalancefactor(Node* root){
    if(root == NULL) 
        return 0;
    return getheight(root->left) - getheight(root->right); 
}