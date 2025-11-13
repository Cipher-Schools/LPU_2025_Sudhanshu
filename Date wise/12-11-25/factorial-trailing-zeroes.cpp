/*
    program to find the number of trailing zeroes in n!
*/
#include <iostream>
using namespace std;
int trailingZeroes(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = trailingZeroes(n);
    cout << "Number of trailing zeroes in " << n << "! is: " << result << endl;
    return 0;
}