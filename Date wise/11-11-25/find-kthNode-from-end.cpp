/*
    program to find the kth node from the end in a singly linked list
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

Node* findKthFromEnd(Node* head, int k) {
    Node* first = head;
    Node* second = head;

    // Move first pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL) return NULL; // k is larger than the length of the list
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second; // second now points to the kth node from the end
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 2;
    Node* kthNode = findKthFromEnd(head, k);
    if (kthNode != NULL) {
        cout << "The " << k << "th node from the end is: " << kthNode->data << endl;
    } else {
        cout << "The list is shorter than " << k << " nodes." << endl;
    }

    return 0;
}