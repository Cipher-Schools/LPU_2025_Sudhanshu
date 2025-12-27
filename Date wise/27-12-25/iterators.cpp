/**
 * Program to demonstrate the use of C++ STL iterators with vector and list.
 * Shows how to traverse, modify, and access elements using iterators.
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    // Vector
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "Vector elements using iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Modifying vector elements using iterator
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        *it += 5; // Increment each element by 5
    }
    cout << "Modified vector elements: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    // List
    list<string> lst = {"Apple", "Banana", "Cherry"};
    cout << "List elements using iterator: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Modifying list elements using iterator
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        *it = *it + " Fruit"; // Append " Fruit" to each element
    }
    cout << "Modified list elements: ";
    for (const auto& l : lst) {
        cout << l << " ";
    }
    cout << endl;

    return 0;
}