/**
 * Program to implement a max stack using two stacks
 * TC: O(1) for push, pop, getMax
 */
#include <iostream>
#include <stack>
using namespace std;
class MaxStack {
    stack<int> mainSt;
    stack<int> maxSt;
public:
    void push(int x) {
        mainSt.push(x);
        if (maxSt.empty() || x >= maxSt.top()) {
            maxSt.push(x);
        }
    }
    void pop() {
        if (mainSt.empty()) return;
        if (mainSt.top() == maxSt.top()) {
            maxSt.pop();
        }
        mainSt.pop();
    }
    int top() {
        if (mainSt.empty()) throw runtime_error("Stack is empty");
        return mainSt.top();
    }
    int getMax() {
        if (maxSt.empty()) throw runtime_error("Stack is empty");
        return maxSt.top();
    }
};
int main() {
    MaxStack st;
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(2);

    cout << "Current Max: " << st.getMax() << endl; // 5
    st.pop();
    cout << "Top Element: " << st.top() << endl;    // 5
    cout << "Current Max: " << st.getMax() << endl; // 5
    st.pop();
    cout << "Current Max: " << st.getMax() << endl; // 3

    return 0;
}