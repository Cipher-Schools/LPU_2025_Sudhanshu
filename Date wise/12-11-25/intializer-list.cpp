/*
    Program to demonstrate initializer lists in C++
*/

#include <iostream>
using namespace std;
class Point {
    int x, y;
public:
    // Constructor using initializer list
    Point(int a, int b) : x(a), y(b) {
        // Body can be empty as initialization is done above
    }
    void display() {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};
int main() {
    Point p1(10, 20);
    Point p2(30, 40);

    p1.display();
    p2.display();

    return 0;
}