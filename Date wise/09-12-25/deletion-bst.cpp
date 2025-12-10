/**
 * Program to demonstrate deletion operation in a Binary Search Tree in C++
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

    // Helper function to find the maximum value node in the BST
    Node* findMax(Node* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Helper function to delete a value from the BST
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the inorder predecessor (largest in the left subtree)
            Node* temp = findMax(node->left);
            // Copy the inorder successor's content to this node
            node->data = temp->data;
            // Delete the inorder successor
            node->left = deleteNode(node->left, temp->data);
        }
        return node;
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
    // Public method to delete a value
    void deleteNode(int val) {
        root = deleteNode(root, val);
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

    cout << "Inorder traversal of the given tree: ";
    tree.inorder();

    cout << "Delete 20\n";
    tree.deleteNode(20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder();

    cout << "Delete 30\n";
    tree.deleteNode(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder();

    cout << "Delete 50\n";
    tree.deleteNode(50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder();

    return 0;
}