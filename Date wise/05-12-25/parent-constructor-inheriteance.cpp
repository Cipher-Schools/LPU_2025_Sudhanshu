/**
 * Program to demonstrate parent constructor inheritance
 */

#include <iostream>
using namespace std;
class A
{
public:
// Parent class A constructors
    // Default constructor
    A()
    {
        cout << "default\n";
    }
    
    // Parameterized constructor with one parameter
    A(int a)
    {
        cout << "A's Parameter " << a << endl;
    }
    
    // Parameterized constructor with two parameters
    A(int a, int b)
    {
        cout << "A's double Parameter " << a << b << endl;
    }
};
class B
{
public:
// Parent class B constructor
    // Parameterized constructor with one parameter
    B(int a)
    {
        cout << "B's Parameter " << a << endl;
    }
};
class C : public A, public B
{
public:
// Child class C constructor
    // Parameterized constructor with two parameters
    C(int a, int b) : A(a, b), B(b)
    {
        cout << "C's call\n";
    }
};
int main()
{
    C ob(3, 5);
    /**
     * Output:
     * A's double Parameter 35
     * B's Parameter 5
     * C's call
     */
    return 0;
}