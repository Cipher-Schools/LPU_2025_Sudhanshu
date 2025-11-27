/**
 * Program to convert a postfix expression to a prefix expression.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(const string& postfix) {
    stack<string> s;
    // Traverse the postfix expression
    for (char c : postfix) {
        // If the character is an operator
        if (isOperator(c)) {
            // Pop two operands from the stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            // Concatenate them in prefix order and push back to stack
            string temp = c + op1 + op2;
            s.push(temp);
        } else {
            // If the character is an operand, push it to the stack
            s.push(string(1, c));
        }
    }
    // The final element in the stack is the prefix expression
    return s.top();
}

int main() {
    string postfix = "ABC*+";
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}