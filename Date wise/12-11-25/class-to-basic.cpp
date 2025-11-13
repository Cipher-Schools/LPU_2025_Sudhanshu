/*
    Program to demonstrate class type to basic type conversion in C++
*/

#include <iostream>
using namespace std;
class Distance {
    int feet;
    int inches;
public:
    Distance(int f, int i) : feet(f), inches(i) {}
    // Conversion operator to convert Distance to float (total feet)
    operator float() {
        return (feet * 12 + inches) / 12.0;
    }
};
int main() {
    Distance d1(5, 8); // 5 feet 8 inches
    float totalFeet = d1; // Implicit conversion to float

    cout << "Total distance in feet: " << totalFeet << " ft\n";

    return 0;
}