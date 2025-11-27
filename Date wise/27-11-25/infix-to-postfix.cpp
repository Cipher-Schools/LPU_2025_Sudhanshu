/**
 * Program to convert infix expression to postfix expression using stack.
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

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        // If the token is an operand, add it to the output
        if (isalnum(token)) {
            postfix += token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            operators.push(token);
        }
        // If the token is ')', pop and output from the stack
        // until an '(' is encountered
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        // If the token is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Pop all the operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+(B*C-(D/E^F)*G)*H";

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}