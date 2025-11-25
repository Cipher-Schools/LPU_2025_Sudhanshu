/**
 * Program to delete the middle element of a stack
 * using only stack operations (push, pop, top, isEmpty)
 * TC: O(n), SC: O(n)
 */
#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int>& st) {
    if (st.empty()) return;
    int mid = st.size() / 2; // lower middle for even size
    stack<int> temp;
    for (int i = 0; i < mid; ++i) {
        temp.push(st.top());
        st.pop();
    }
    st.pop(); // remove middle
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original Stack: ";
    printStack(st);

    deleteMid(st);

    cout << "Stack after deleting middle element: ";
    printStack(st);

    return 0;
}
