/*
    Program to swap only values of nodes of a linked list in pairs.
*/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
Node *swapValuesInPairs(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        // Swap values of current node and next node
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;

        // Move to the next pair
        curr = curr->next->next;
    }
    return head;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = swapValuesInPairs(head);

    cout << "List after swapping values in pairs: ";
    printList(head);

    return 0;
}