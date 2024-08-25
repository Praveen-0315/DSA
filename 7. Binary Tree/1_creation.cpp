#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildBinaryTree(node *root)
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting on left: " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter data for inserting on right: " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

node* buildfromLevelOrder(node* root){
    queue<node*> q;
    cout<<"Enter data of root node: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<"Enter data of left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data of right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrderTraversal(node *root)
{
    
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int height = 0;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
                height++;
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
    cout<<"height of binary tree is: "<<height<<endl;
}

void Inorder(node *root){
    //base case
    if(root == NULL){
        return ;
    }
    // LNR
    Inorder(root->left);
    cout<<root->data<<"  ";
    Inorder(root->right);

}
void preorder(node *root){
    //base case
    if(root == NULL){
        return ;
    }
    //NLR
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(node *root){
    //base case
    if(root == NULL){
        return ;
    }
    //LRN
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";

}

int main()
{
    node *root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = buildfromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    // root = buildBinaryTree(root);
    cout << "printing level order tranversal" << endl;
    levelOrderTraversal(root);

    // cout<<"inorder ";
    // Inorder(root);
    // cout<<"preorder ";
    // preorder(root);
    // cout<<"postorder ";
    // postorder(root);
    return 0;
}