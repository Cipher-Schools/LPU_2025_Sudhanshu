/**
 * Program to demonstrate conversion from basic data types to class types in C++
 */

#include <iostream>
using namespace std;
class Distance {
    int feet;
    int inches;
public:
    // Constructor to initialize Distance from an integer (total inches)
    Distance(int totalInches) {
        feet = totalInches / 12;
        inches = totalInches % 12;
    }
    int getFeet() const { return feet; }
    int getInches() const { return inches; }
};
int main() {
    int totalInches;
    cout << "Enter total inches: ";
    cin >> totalInches;

    Distance d = totalInches;
    cout << "Distance: " << d.getFeet() << " feet " << d.getInches() << " inches\n";

    return 0;
}