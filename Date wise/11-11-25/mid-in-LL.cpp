/*
    Program to find the middle node in a singly linked list.
*/

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* findMiddleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer will be at the middle node
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node* middleNode = findMiddleNode(head);
    if (middleNode != NULL) {
        cout << "The middle node value is: " << middleNode->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}