#include<iostream> 
using namespace std;

// class A{
// public:
//     A() { cout << "Constructor A" << endl; }
//     ~A() { cout << "Destructor A" << endl; }
// };
class B{
public:
    B() { cout << "Constructor B" << endl; }
    ~B() { cout << "Destructor B" << endl; }
};
class C{
public:
    C() { cout << "Constructor C" << endl; }
    ~C() { cout << "Destructor C" << endl; }
};
class D: public C, public B{
public:
    D() { cout << "Constructor D" << endl; }
    ~D() { cout << "Destructor D" << endl; }
};
// class E: public D{
// public:
//     E() { cout << "Constructor E" << endl; }
//     ~E() { cout << "Destructor E" << endl; }
// };

int main()
{
    D obj;
return 0;
}