/*
    Program to demonstrate various string modifiers in C++
*/

#include <iostream>
#include <string>
using namespace std;
int main() {
    // Initializing a string
    string str = "Hello, World!";
    cout << "Original String: " << str << endl;

    // 1. append() - Appending a string
    str.append(" Welcome to C++ programming.");
    cout << "After append(): " << str << endl;  // Hello, World! Welcome to C++ programming.

    // 2. insert() - Inserting a substring at a specific position
    str.insert(13, " Beautiful");
    cout << "After insert(): " << str << endl;  // Hello, World! Beautiful Welcome to C++ programming.

    // 3. erase() - Erasing a part of the string
    str.erase(13, 10); // Erase " Beautiful"
    cout << "After erase(): " << str << endl; // Hello, World! Welcome to C++ programming.

    // 4. replace() - Replacing a part of the string
    str.replace(7, 5, "Universe");
    cout << "After replace(): " << str << endl; // Hello, Universe! Welcome to C++ programming.

    // 5. clear() - Clearing the entire string
    str.clear();
    cout << "After clear(): '" << str << "'" << endl; // ''

    // 6. push_back() - Adding characters one by one
    str.push_back('C');
    str.push_back('+');
    str.push_back('+');
    cout << "After push_back(): " << str << endl; // C++

    // 7. pop_back() - Removing the last character
    str.pop_back();
    cout << "After pop_back(): " << str << endl; // C+

    return 0;
}