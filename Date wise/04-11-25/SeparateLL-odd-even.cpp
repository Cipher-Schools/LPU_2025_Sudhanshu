/*
    Separate LL into odd and even node values
    eg: 1->2->3->4->5->NULL
    odd LL: 1->3->5->NULL
    even LL: 2->4->NULL
*/

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void separateOddEven(Node* head, Node*& oddHead, Node*& evenHead) {
    Node *dummyOdd = new Node(0);
    Node *dummyEven = new Node(0);
    Node* oddTail = dummyOdd;
    Node* evenTail = dummyEven;

    Node* current = head;

    while (current) {
        if (current->data % 2 != 0) { // Odd
            oddTail->next = current;
            oddTail = current;
        } else { // Even
            evenTail->next = current;
            evenTail = current;
        }
        current = current->next;
    }

    // terminate both lists
    oddTail->next = nullptr;
    evenTail->next = nullptr;

    // assign heads
    oddHead = dummyOdd->next;
    evenHead = dummyEven->next;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original List: ";
    printList(head);

    Node* oddHead = nullptr;
    Node* evenHead = nullptr;
    separateOddEven(head, oddHead, evenHead);

    cout << "Odd List: ";
    printList(oddHead);

    cout << "Even List: ";
    printList(evenHead);

    return 0;
}