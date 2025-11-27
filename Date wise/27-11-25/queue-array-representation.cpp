/**
 * Program to implement queue using array.
 * TC: O(1) for enqueue and dequeue operations
 * SC: O(n) for storing n elements in the queue
 */

#include <iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int* queue;
public:
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        queue = new int[capacity];
    }
    ~Queue() {
        delete[] queue;
    }
    void enqueue(int data) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        queue[++rear] = data;
    }
    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return queue[front++];
    }
    bool isEmpty() {
        return front > rear;
    }
    bool isFull() {
        return rear == capacity - 1;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element is: " << q.peek() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // This will show overflow

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    q.dequeue(); // This will show underflow

    return 0;
}