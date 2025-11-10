/*
    Program to merge two sorted linked list into one sorted linked list.
*/
#include <iostream>
using namespace std;
// Node for the singly linked list
struct Node {
    int data;      // payload
    Node* next;    // pointer to next node
};
// Head points to first node.
Node* head = nullptr;
// Insert a new node with 'value' at the end of the list.
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd length, slow will be at the middle
    // For even length, slow will be at the start of the second half
    return slow;
}

Node* merge(Node* list1, Node* list2) {
    Node* mergedHead = nullptr;
    Node** lastPtrRef = &mergedHead;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            *lastPtrRef = list1;
            list1 = list1->next;
        } else {
            *lastPtrRef = list2;
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // Append any remaining elements from either list
    *lastPtrRef = (list1) ? list1 : list2;

    return mergedHead;
}
int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    insert(1);
    insert(3);
    insert(5);
    Node* list1 = head;

    // Reset head for second list
    head = nullptr;

    // Create second sorted linked list: 2 -> 4 -> 6
    insert(2);
    insert(4);
    insert(6);
    Node* list2 = head;

    // Merge the two sorted linked lists
    Node* mergedList = merge(list1, list2);

    // Print the merged sorted linked list
    Node* temp = mergedList;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}