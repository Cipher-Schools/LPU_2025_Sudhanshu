/**
 * Program to implement a stack using a single queue.
 * The stack should support standard operations like push, pop, top, and isEmpty.
 * We will use a single queue to achieve this functionality.
 * For the push operation, we will add the new element to the queue and then rotate the queue
 * to ensure that the new element is at the front of the queue, simulating stack behavior
 * for pop and top operations.
 */

#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q; // Single queue to implement stack behavior
public:
    // Push operation
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate the queue to move the newly added element to the front
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    // Pop operation
    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }
    // Top operation
    int top() {
        if (!q.empty()) {
            return q.front();
        }
        return -1; // Stack is empty
    }
    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // Should print 30
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Should print 20
    stack.pop();
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Should print No
    stack.pop();
    cout << "Is stack empty after popping all elements? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}