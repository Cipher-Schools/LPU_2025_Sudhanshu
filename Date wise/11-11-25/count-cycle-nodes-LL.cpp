/*
    Program to count the number of nodes in cycle in a singly linked list.
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
int countCycleNodes(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd's Tortoise and Hare algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            int count = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count; // Return the number of nodes in the cycle
        }
    }
    return 0; // No cycle
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    // Creating a cycle for testing
    head->next->next->next->next->next = head->next; // 50 points to 20

    int cycleNodeCount = countCycleNodes(head);
    if (cycleNodeCount > 0) {
        cout << "Number of nodes in the cycle: " << cycleNodeCount << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
