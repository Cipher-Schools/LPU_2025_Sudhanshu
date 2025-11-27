/**
 * Program to convert a prefix expression to a postfix expression.
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(const string& prefix) {
    stack<string> s;
    // Traverse the prefix expression in reverse order
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        // If the character is an operator
        if (isOperator(c)) {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            // Concatenate them in postfix order and push back to stack
            string temp = op1 + op2 + c;
            s.push(temp);
        } else {
            // If the character is an operand, push it to the stack
            s.push(string(1, c));
        }
    }
    // The final element in the stack is the postfix expression
    return s.top();
}

int main() {
    string prefix = "+A*BC";
    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}