/**
 * Create a binary tree using an array representation
 */
#include<iostream>
using namespace std;

// Node structure for binary tree
struct Node{
    int data;
    Node* left;
    Node* right;
};

// Create binary tree from array using level-order representation
// arr: input array, n: array size, i: current index
Node* createTree(int arr[], int n, int i){
    if(i >= n || arr[i] == -1) return nullptr;
    Node* root = new Node{arr[i], nullptr, nullptr};
    root->left = createTree(arr, n, 2*i + 1);   // left child at 2*i + 1
    root->right = createTree(arr, n, 2*i + 2);  // right child at 2*i + 2
    return root;
}

// Print tree in preorder (root, left, right)
void preorder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);    
}

// Print tree in inorder (left, root, right)
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}

// Print tree in postorder (left, right, root)
void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);    
    cout<<root->data<<" ";
}

int main()
{
    // Array representation of binary tree (-1 indicates null)
    int arr[] = {1, 2, 3, 4, -1, 6, -1, 8, 9, -1, -1};
    //        1
    //       / \
    //      2   3
    //     /   /
    //    4   6
    //   / \
    //  8   9
    
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = createTree(arr, n, 0);
    
    cout<<"PreOrder: ";
    preorder(root);
    cout<<endl;
    
    cout<<"InOrder: ";
    inorder(root);
    cout<<endl;
    
    cout<<"PostOrder: ";
    postorder(root);
    cout<<endl;
    
    return 0;
}