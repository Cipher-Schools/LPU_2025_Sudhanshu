/**
 * Program to implement queue using linked list.
 */

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {
            front = rear;
        }
    }
    void dequeue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    }
    int peek() {
        if (!front) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue elements: ";
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Queue after dequeue: ";
    q.display();
    return 0;
}