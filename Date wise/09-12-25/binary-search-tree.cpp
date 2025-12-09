/**
 * Program to demostrate Binary Search Tree operations in C++
 */

#include <iostream>
using namespace std;
// Definition of a node in the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Class representing the Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a value into the BST
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to search for a value in the BST
    bool search(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }
public:
    BST() : root(nullptr) {}
    // Public method to insert a value
    void insert(int val) {
        root = insert(root, val);
    }

    // Public method for inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Public method to search for a value
    bool search(int val) {
        return search(root, val);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal of the BST: ";
    tree.inorder();

    int key = 40;
    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    key = 90;
    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    return 0;
}