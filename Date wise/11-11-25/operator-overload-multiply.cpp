/*
    Program to oveload the multiplication operator for a complex number class.
*/
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // Overload the multiplication operator
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3); // 2 + 3i
    Complex c2(4, 5); // 4 + 5i

    Complex c3 = c1 * c2; // Using overloaded * operator

    cout << "Result of multiplication: ";
    c3.display(); // Should display the result of (2 + 3i) * (4 + 5i)

    return 0;
}