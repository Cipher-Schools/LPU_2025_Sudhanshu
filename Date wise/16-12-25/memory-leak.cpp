/**
 * Programer: Memory Leak Example in C++
 */

#include <iostream>
using namespace std;

void function_to_test_memory_leak() {
    // Allocating memory on the heap
    int* leak = new int[100];
    // Intentionally not deleting the allocated memory to create a memory leak
    cout << "Memory allocated but not freed, causing a memory leak." << endl;
}

int main(){
    function_to_test_memory_leak();
    return 0;
}
