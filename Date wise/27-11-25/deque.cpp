/**
 * Program to demonstrate the usage of STL deque in C++
 */

#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;

    // Add elements to the back of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Add elements to the front of the deque
    dq.push_front(5);
    dq.push_front(1);

    // Display the contents of the deque
    cout << "Deque contents: ";
    for (const int& elem : dq) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements from the front and back
    dq.pop_front();
    dq.pop_back();

    // Display the contents after popping
    cout << "Deque after popping front and back: ";
    for (const int& elem : dq) {
        cout << elem << " ";
    }
    cout << endl;

    // Accessing elements using indexing
    cout << "Element at index 1: " << dq[1] << endl;

    // Size of the deque
    cout << "Size of deque: " << dq.size() << endl;

    return 0;
}