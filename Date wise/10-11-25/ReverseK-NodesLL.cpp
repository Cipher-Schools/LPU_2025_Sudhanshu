/*
    Program to reverse K nodes in a linked list.
    Time Complexity: O(n)
*/
#include <iostream>
using namespace std;
// Node structure for singly linked list
struct Node
{
    int data;
    Node *next;
};
// Function to create a new node with given value
Node *newNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *pre = NULL;
    while (head != NULL)
    {
        Node *a = head->next;
        head->next = pre;
        pre = head;
        head = a;
    }
    return pre;
}
Node *findK(Node *head, int k)
{
    Node *t = head;
    int i = 1;
    while (head != NULL)
    {
        if (i == k)
            return head;
        i++;
        head = head->next;
    }
    return t;
}
// Function to reverse K nodes in the linked list
Node *reverseKNodes(Node *head, int k)
{
    Node *joiner = NULL, *kth = NULL, *h = NULL, *nextNode = NULL;

    while (head != NULL)
    {

        kth = findK(head, k);
        if (h == NULL)
            h = kth;
        nextNode = kth->next;
        kth->next = NULL;
        Node *rev = reverse(head);
        if (joiner != NULL)
        {
            joiner->next = rev;
        }
        joiner = head;
        head = nextNode;
    }
    return h;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

    int k = 3;
    cout << "Original list: ";
    printList(head);

    head = reverseKNodes(head, k);

    cout << "Reversed list in groups of " << k << ": ";
    printList(head);

    return 0;
}