/*
    Program to find the cycle in a singly linked list and return the starting node of the cycle.
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

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd's Tortoise and Hare algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            // Find the starting node of the cycle
            Node* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Return the starting node of the cycle
        }
    }
    return NULL; // No cycle
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    // Creating a cycle for testing
    head->next->next->next->next->next = head->next; // 50 points to 20

    Node* cycleStartNode = detectCycle(head);
    if (cycleStartNode != NULL) {
        cout << "Cycle detected at node with value: " << cycleStartNode->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}