/*
Rotate a linked list to the right by k places.
*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // Compute the length of the list and get the tail node
    ListNode* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Make the list circular
    tail->next = head;

    // Find the new tail: (length - k % length - 1)th node
    // and the new head: (length - k % length)th node
    k = k % length;
    ListNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;

    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list:\n";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "Rotated list by " << k << " places:\n";
    printList(head);

    return 0;
}