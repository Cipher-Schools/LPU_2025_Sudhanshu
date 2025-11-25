/**
 * Program to increase the count every time this file is run
 * TC  : O(1)
 */
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    const char* filename = "counter.txt";
    int count = 0;

    // Try to open the file to read the current count
    ifstream inFile(filename);
    if (inFile) {
        inFile >> count; // Read the existing count
        inFile.close();
    }

    // Increment the count
    count++;

    // Open the file to write the updated count
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }
    outFile << count; // Write the updated count
    outFile.close();

    cout << "This file has been run " << count << " times." << endl;
    return 0;
}