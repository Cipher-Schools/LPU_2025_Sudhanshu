/**
 * Program to open, read, write and close a file in C++14
 * TC  : O(n) where n is number of characters read/written
 */

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Open a file in write mode
    ofstream outFile("example.txt");
    if (!outFile) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    // Write to the file
    outFile << "Hello, World!" << endl;
    outFile << "This is a sample file." << endl;
    outFile.close(); // Close the file after writing

    // Open the file in read mode
    ifstream inFile("example.txt");
    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    // Read from the file
    string line;
    while (getline(inFile, line)) {
        cout << line << endl; // Output the content to console
    }
    inFile.close(); // Close the file after reading

    return 0;
}