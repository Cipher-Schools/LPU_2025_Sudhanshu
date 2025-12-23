/**
 * Programt to demonstrate the use of class templates in C++.
 * This example defines a simple class template for a Pair that can hold two values of any types.
 * TC: O(1) for operations like getting and setting values.
 */
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void setFirst(T1 f) {
        first = f;
    }

    void setSecond(T2 s) {
        second = s;
    }

    void display() const {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    // Create a Pair of int and double
    Pair<int, double> p1(1, 2.5);
    p1.display();

    // Create a Pair of string and char
    Pair<string, char> p2("Hello", 'A');
    p2.display();

    // Modify values
    p1.setFirst(10);
    p1.setSecond(20.5);
    p1.display();

    return 0;
}