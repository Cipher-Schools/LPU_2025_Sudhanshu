/**
 * Program to implement Tower of Hanoi problem in C++ using recursion.
 * The Tower of Hanoi is a classic problem that involves moving a set of disks from one peg to another,
 * following specific rules: only one disk can be moved at a time, a disk can only be placed on top of a larger disk,
 * and only the top disk of any peg can be moved.
 * TC: O(2^n) where n is the number of disks.
 * SC: O(n) for the recursion stack.
 */

#include <iostream>
using namespace std;
void towerOfHanoi(int n, char a, char b, char c) { // a-> source, b-> destination, c-> auxiliary
    if (n == 1) {
        cout << "Move disk 1 from peg " << a << " to peg " << b << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from peg " << a << " to peg " << b << endl;
    towerOfHanoi(n - 1, c, b, a);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}