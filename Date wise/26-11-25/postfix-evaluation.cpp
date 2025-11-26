/**
 * Program to evaluate postfix expression using a stack
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
    return 0; // Default (should not occur in valid postfix input)
}

// Function to evaluate a postfix expression
int evaluate(const string& expression) {
    stack<int> values;  // Stack to store numbers

    for (size_t i = 0; i < expression.length(); i++) {

        // Skip spaces
        if (isspace((unsigned char)expression[i])) continue;

        // If digit is found, read the full number
        if (isdigit((unsigned char)expression[i])) {
            int val = 0;

            // Build the number (handles multi-digit numbers)
            while (i < expression.length() && isdigit((unsigned char)expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }

            values.push(val);
            i--;  // Adjust since the loop will increment i
        }
        // If an operator is found
        else if (isOperator(expression[i])) {

            // Pop top two values from stack
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();

            // Apply operator and push result
            int result = applyOp(a, b, expression[i]);
            values.push(result);
        }
        // Ignore any other character (simple logic)
    }

    // Final result is the only value remaining
    return values.top();
}

int main() {
    // Example postfix expression
    string expression = "12 3 4 * + 6 -";

    int result = evaluate(expression);

    cout << "Result: " << result << endl;

    return 0;
}
