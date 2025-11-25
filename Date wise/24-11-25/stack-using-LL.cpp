/**
 * Program to implement stack using Linked List
 * TC  : O(1) for push, pop, peek, isEmpty
 * SC  : O(n) where n is number of elements in stack
 */
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    int poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is: " << s.peek() << endl;
    return 0;
}