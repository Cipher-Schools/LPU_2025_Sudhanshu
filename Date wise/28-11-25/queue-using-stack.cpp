/**
 * Program to implement a Queue using two Stacks.
 * The Queue should support standard operations like enqueue, dequeue, and front.
 * We will use two stacks to achieve this functionality.
 * The first stack is used for enqueue operations, and the second stack is used for dequeue operations.
 * When dequeueing, if the second stack is empty, we transfer all elements from the first stack to the second stack.
 * This ensures that the elements are in the correct order for dequeueing.
 * If both stacks are empty during a dequeue or front operation, we will indicate that the queue is empty.
 * If the queue is empty, we will return -1 for dequeue and front operations.
 */

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1; // Stack for enqueue operations
    stack<int> stack2; // Stack for dequeue operations

    // Helper function to transfer elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
public:
    // Enqueue operation
    void enqueue(int x) {
        stack1.push(x);
    }
    // Dequeue operation
    int dequeue() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        if (stack2.empty()) {
            return -1; // Queue is empty
        }
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }
    // Front operation
    int front() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        if (stack2.empty()) {
            return -1; // Queue is empty
        }
        return stack2.top();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.front() << endl; // Should print 10

    cout << "Dequeue element: " << queue.dequeue() << endl; // Should print 10
    cout << "Front element: " << queue.front() << endl; // Should print 20

    queue.enqueue(40);
    cout << "Dequeue element: " << queue.dequeue() << endl; // Should print 20
    cout << "Dequeue element: " << queue.dequeue() << endl; // Should print 30
    cout << "Front element: " << queue.front() << endl; // Should print 40
    cout << "Dequeue element: " << queue.dequeue() << endl; // Should print 40
    cout << "Dequeue element: " << queue.dequeue() << endl; // Should print -1 (Queue is empty)

    return 0;
}