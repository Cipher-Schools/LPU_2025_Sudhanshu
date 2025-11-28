/**
 * Program to find the Next Greater Element for each element in an array.
 * The Next Greater Element for an element x is the first greater element on the right side of x in the array.
 * If no such element exists, we return -1 for that element.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s; // Stack to keep track of elements

    for (int i = 0; i < n; ++i) {
        // While stack is not empty and the current element is greater than the element at the index stored at the top of the stack
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i]; // Update the result for the index at the top of the stack
            s.pop(); // Remove the index from the stack
        }
        s.push(i); // Push current index onto the stack
    }

    return result; // Return the result array
}

int main() {
    vector<int> nums = {4, 5, 2, 25, 7, 8};
    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}