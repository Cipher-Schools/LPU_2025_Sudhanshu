/**
 * Program to evaluate a simple infix expression using two stacks
 * TC: O(n)
 * SC: O(n)
 */

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Apply operator to two numbers
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;  // Assume no division by zero in input
    return 0;
}

// Evaluate expression (simplified, no error checking)
int evaluate(const string& expression) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < expression.length(); i++) {

        if (isspace((unsigned char)expression[i])) continue;

        // Parse number
        if (isdigit((unsigned char)expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit((unsigned char)expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; 
        }
        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); // Remove '('
        }
        // Operator
        else if (isOperator(expression[i])) {
            while (!ops.empty() && ops.top() != '(' &&
                   precedence(ops.top()) >= precedence(expression[i])) {

                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    // Apply all remaining operators
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression = "(10 + 2) * 6";
    cout << "Result: " << evaluate(expression) << endl;
    return 0;
}
