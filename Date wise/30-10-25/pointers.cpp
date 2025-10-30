#include <iostream>
using namespace std;

struct MyObj
{
    int v;
    void show() const { cout << "MyObj.v = " << v << '\n'; }
};

// Void pointer: can hold address of any object, but must be cast to be dereferenced.
void voidPointerExample()
{
    int x = 42;
    void *vp = &x; // holds address, but type-erased
    // cout << *vp;              // ERROR: cannot dereference void*
    int *ip = (int *)vp; // cast back to int*
    cout << "void->int cast: " << *ip << '\n';

    // pointer arithmetic not allowed on void* in standard C++; convert to char* for byte math
    char *cp = (char *)vp;
    cout << "char: " << *cp << '\n';
}

// Null pointer: a sentinel value meaning "points to nothing".
// Always initialize pointer to nullptr if it doesn't point to valid storage.
void nullPointerExample()
{
    int *p = nullptr; // safe, well-defined null pointer
    if (p)
    {
        cout << *p << '\n';
    }
    else
    {
        cout << "p is nullptr; do not dereference\n";
    }
}

// Dangling pointer: points to memory that is no longer valid (common causes: local stack object expired, deleted heap memory).
int *createDangling()
{
    int local = 7;
    return &local; // BAD: returns address of local stack variable -> dangling
}
void danglingPointerExample()
{
    int *p = createDangling();
    // Dereferencing p is undefined behavior; might crash or print garbage:
    cout << "Dangling pointer (UB) example: " << p << " (don't dereference)\n";

    int *q = new int(10);
    delete q;
    // q now points to freed memory -> also dangling until reset:
    cout << "After delete q = " << q << " (dangling)\n";
    q = nullptr; // fix: reset to nullptr after delete
}

// Wild pointer: an uninitialized pointer that contains an indeterminate value.
// Always initialize pointers; wild pointers often cause crashes.
void wildPointerExample()
{
    int *p; // uninitialized -> wild
    // cout << *p << '\n';        // UB: could crash
    p = nullptr; // initialize before use
    cout << "Initialized wild pointer to nullptr\n";
}

// Pointer to pointer: holds address of another pointer. Useful for dynamic APIs or modifying a pointer in a function.
void pointerToPointerExample()
{
    int x = 5;
    int *p = &x;
    int **pp = &p; // pointer to pointer
    cout << "x = " << x << ", *p = " << *p << ", **pp = " << **pp << '\n';

    // modify p through pp:
    static int y = 99;
    *pp = &y;
    cout << "after *pp=&y -> *p = " << *p << '\n';
}

// Pointer to objects (class/struct): access members with ->, and manage lifetime carefully.
void pointerToObjectExample()
{
    MyObj obj{123};
    MyObj *po = &obj; // pointer to stack object
    po->show();

    MyObj *ph = new MyObj{456}; // pointer to heap object
    ph->show();
    delete ph; // must delete to avoid leak
    ph = nullptr;
}

int main()
{
    cout << "Void pointer example:\n";
    voidPointerExample();
    cout << "\nNull pointer example:\n";
    nullPointerExample();
    cout << "\nDangling pointer example:\n";
    danglingPointerExample();
    cout << "\nWild pointer example:\n";
    wildPointerExample();
    cout << "\nPointer-to-pointer example:\n";
    pointerToPointerExample();
    cout << "\nPointer-to-object example:\n";
    pointerToObjectExample();
    return 0;
}
// ...existing code...