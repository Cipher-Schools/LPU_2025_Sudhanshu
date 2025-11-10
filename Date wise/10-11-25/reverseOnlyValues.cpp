/*
    program to reverse only the values of nodes in k group in a linked list
    time complexity: O(n)
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

Node* reverseValues(Node* head, int k)
{
    if (head == NULL || head->next == NULL || k <= 1)
        return head;

    Node* current = head;
    Node* joiner = NULL;
    Node* newHead = NULL;

    while (current != NULL)
    {
        // Collect values of k nodes
        int count = 0;
        Node* temp = current;
        int* values = new int[k];
        while (temp != NULL && count < k)
        {
            values[count] = temp->data;
            temp = temp->next;
            count++;
        }

        // Reverse the collected values
        for (int i = 0; i < count / 2; i++)
        {
            swap(values[i], values[count - i - 1]);
        }

        // Assign reversed values back to the nodes
        temp = current;
        for (int i = 0; i < count; i++)
        {
            temp->data = values[i];
            temp = temp->next;
        }

        delete[] values;

        // Move to the next group
        for (int i = 0; i < count; i++)
        {
            if (current != NULL)
                current = current->next;
        }
    }

    return head;
}

// Helper function to print the linked list
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = newNode(1);
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

    head = reverseValues(head, k);

    cout << "List after reversing values in groups of " << k << ": ";
    printList(head);

    return 0;
}