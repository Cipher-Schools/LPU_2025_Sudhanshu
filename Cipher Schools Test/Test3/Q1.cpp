/*
    Write a cpp program to check for palindrome in Linked list.
    A palindrome is a sequence that reads the same backward as forward.
    For example, the linked list 1 -> 2 -> 3 -> 2 -> 1 is a palindrome.
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
// Time: O(n)
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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // new head of reversed list
}

bool compareLists(Node* first, Node* second) {
    while (first && second) {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

bool isPalindrome() {
    if (!head || !head->next)
        return true;

    // 1️⃣ Find the middle
    Node* middle = findMiddle(head);

    // 2️⃣ Reverse the second half
    Node* secondHalf = reverseList(middle);

    // 3️⃣ Compare both halves
    bool palindrome = compareLists(head, secondHalf);

    // (Optional) Restore the original list
    reverseList(secondHalf);

    return palindrome;
}


int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    insert(1);

    // Check if the linked list is a palindrome
    if (isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}