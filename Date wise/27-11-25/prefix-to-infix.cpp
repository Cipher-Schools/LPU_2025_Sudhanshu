/**
 * Program to convert a prefix expression to a infix expression.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert prefix expression to infix expression
string prefixToInfix(const string& prefix) {
    stack<string> s;

    // Traverse the prefix expression in reverse order
    for (int i = prefix.length() - 1; i >= 0; --i) {
        char token = prefix[i];

        // If the token is an operator
        if (isOperator(token)) {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form a new infix expression and push it back to the stack
            string expr = "(" + op1 + token + op2 + ")";
            s.push(expr);
        }
        // If the token is an operand, push it to the stack
        else {
            s.push(string(1, token));
        }
    }

    // The final element in the stack is the complete infix expression
    return s.top();
}

int main() {
    string prefix = "*+AB-CD";
    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}