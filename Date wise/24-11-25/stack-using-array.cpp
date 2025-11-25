/**
 * Program to implement stack using array
 * TC  : O(1) for push, pop, peek, isEmpty, isFull
 * SC  : O(n) where n is size of stack
 */

#include <iostream>
using namespace std;
#define MAX 1000
class Stack {
    int top;
    int arr[MAX];
    public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return false;
    }
    arr[++top] = x;
    return true;
}
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top--];
}
int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return arr[top];
}
bool Stack::isEmpty() {
    return top == -1;
}
bool Stack::isFull() {
    return top == MAX - 1;
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