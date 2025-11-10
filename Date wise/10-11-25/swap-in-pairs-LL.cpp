/*
    Program to swap nodes of a linked list in pairs.
    For example, if the linked list is 1->2->3->4, the
    output should be 2->1->4->3.
*/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};


Node *swapPairs(Node *head)
{
    Node *temp = NULL;
    Node *ret = NULL;
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (temp != NULL)
        {
            temp->next->next = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        if (ret == NULL)
            ret = temp;
        curr = curr->next;
    }
    return ret == NULL ? head : ret;
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

    head = swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(head);

    return 0;
}