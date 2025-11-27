/**
 * Program to convert a infix expression to prefix expression using stack.
 */

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    stack<char> operators;
    string prefix;
    string reversedInfix = reverseString(infix);

    for (char token : reversedInfix) {
        // If the token is an operand, add it to the output
        if (isalnum(token)) {
            prefix += token;
        }
        // If the token is ')', push it to the stack
        else if (token == ')') {
            operators.push(token);
        }
        // If the token is '(', pop and output from the stack
        // until an ')' is encountered
        else if (token == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop ')'
        }
        // If the token is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) > precedence(token)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Pop all the operators from the stack
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    return reverseString(prefix);
}

int main() {
    string infix = "A+B*(C^D-E)";

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}