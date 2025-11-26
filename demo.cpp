#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[50]; // Use array, not string!
    float gpa;
};

int main() {
    Student s1 = {101, "Aarav", 9.5};
    
    // WRITE object
    ofstream outFile("student.dat", ios::binary);
    outFile.write((char*)&s1, sizeof(s1));
    outFile.close();

    // READ object
    Student s2;
    ifstream inFile("student.dat", ios::binary);
    inFile.read((char*)&s2, sizeof(s2));
    
    cout << "Loaded: " << s2.name << ", GPA: " << s2.gpa << endl;
    return 0;
}


