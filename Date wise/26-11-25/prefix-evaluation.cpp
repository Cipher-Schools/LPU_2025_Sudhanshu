/**
 * Program to evaluate an prefix expression using a stack
 * TC: O(n)
 * SC: O(n)
 */

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Check if a character is a valid operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Apply an operator on two operands (simple logic, no error checking)
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;   // Assuming b is never zero
    return 0; // Default (should not occur in valid prefix input)
}

// Function to evaluate a prefix expression
int evaluate(const string& expression) {
    stack<int> values;  // Stack to store numbers

    // Traverse the expression from right to left
    for (int i = expression.length() - 1; i >= 0; i--) {

        // Skip spaces
        if (isspace((unsigned char)expression[i])) continue;

        // If digit is found, read the full number
        if (isdigit((unsigned char)expression[i])) {
            int val = 0;
            int base = 1;

            // Build the number (handles multi-digit numbers)
            while (i >= 0 && isdigit((unsigned char)expression[i])) {
                val = val + (expression[i] - '0') * base;
                base *= 10;
                i--;
            }

            values.push(val);
            i++;  // Adjust since the loop will decrement i
        }
        // If an operator is found
        else if (isOperator(expression[i])) {

            // Pop top two values from stack
            int a = values.top(); values.pop();
            int b = values.top(); values.pop();

            // Apply operator and push result
            int result = applyOp(a, b, expression[i]);
            values.push(result);
        }
        // Ignore any other character (simple logic)
    }

    // The final result will be the only value left in the stack
    return values.top();
}

int main() {
    string expression = "-+7*45+20"; // Example prefix expression
    cout << "Prefix Expression: " << expression << endl;
    cout << "Evaluated Result: " << evaluate(expression) << endl;
    return 0;
}