/**
 * Program to demonstrate the use of C++ STL containers: vector, list, and map.
 * Shows basic operations like insertion, deletion, and traversal.
 * TC: O(1) for insertions/deletions in list and map, O(n) for traversal
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main() {
    // Vector
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Vector elements: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    // List
    list<string> lst;
    lst.push_back("Hello");
    lst.push_back("World");
    cout << "List elements: ";
    for (const auto& l : lst) {
        cout << l << " ";
    }
    cout << endl;

    // Map
    map<int, string> mp;
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    cout << "Map elements: " << endl;
    for (const auto& pair : mp) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}