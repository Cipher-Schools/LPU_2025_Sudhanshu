/**
 * Create a binary tree and perform PreOrder, InOrder and PostOrder traversals
 */

#include<iostream> 
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void preorder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);    
}
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}
void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);    
    cout<<root->data<<" ";
}

int main()
{
    Node* root = new Node{1,nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{5, nullptr, nullptr};
    root->left->left = new Node{3, nullptr, nullptr};
    root->left->right = new Node{4, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};
    root->right->right->left = new Node{8, nullptr, nullptr};
    root->right->right->right = new Node{9, nullptr, nullptr};
    cout<<"PreOrder: ";
    preorder(root);
    cout<<endl;
    cout<<"InOrder: ";
    inorder(root);
    cout<<endl;
    cout<<"PostOrder: ";
    postorder(root);
return 0;
}

