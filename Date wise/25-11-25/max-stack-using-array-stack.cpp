/**
 * Program to implement a max stack using one stack and an array.
 * The max stack supports push, pop, and getMax operations in O(1) time.
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class MaxStack {
private:
    stack<int> mainStack;          // Main stack to store elements
    vector<int> maxArray;          // Array to store maximums
public:
    // Pushes an element onto the stack
    void push(int x) {
        mainStack.push(x);
        if (maxArray.empty() || x >= maxArray.back()) {
            maxArray.push_back(x);
        }
    }
    // Pops the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int topElement = mainStack.top();
        mainStack.pop();
        if (topElement == maxArray.back()) {
            maxArray.pop_back();
        }
    }
    // Returns the maximum element in the stack
    int getMax() {
        if (maxArray.empty()) {
            cout << "Stack is empty. No maximum." << endl;
            return -1; // Indicating stack is empty
        }
        return maxArray.back();
    }
    // Returns the top element of the stack
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Indicating stack is empty
        }
        return mainStack.top();
    }
    // Checks if the stack is empty
    bool isEmpty() {
        return mainStack.empty();
    }
};
int main() {
    MaxStack maxStack;
    maxStack.push(3);
    maxStack.push(5);
    cout << "Current Max: " << maxStack.getMax() << endl; // 5
    maxStack.push(2);
    maxStack.push(1);
    cout << "Current Max: " << maxStack.getMax() << endl; // 5
    maxStack.pop();
    cout << "Current Max: " << maxStack.getMax() << endl; // 5
    maxStack.pop();
    cout << "Current Max: " << maxStack.getMax() << endl; // 5
    maxStack.push(6);
    cout << "Current Max: " << maxStack.getMax() << endl; // 6
    return 0;
}