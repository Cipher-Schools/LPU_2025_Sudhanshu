#include <iostream>
#include <fstream>
#include <limits>   // for numeric_limits used when clearing input
using namespace std;

// Simple student record stored in a binary file
struct Student {
    char name[50];
    int roll;
};

const char* FILENAME = "students.dat";

// Show one student
void showStudent(const Student& s) {
    cout << "\n------------------------\n";
    cout << "Name  : " << s.name << "\n";
    cout << "Roll  : " << s.roll << "\n";
    cout << "------------------------\n";
}

// Create 3 fixed records and write them to a binary file
void createRecords() {
    Student arr[3] = {
        {"Alice Johnson", 101},
        {"Bob Williams", 102},
        {"Charlie Brown", 103}
    };

    // ios::binary so data is written exactly as in memory
    // ios::trunc (default with plain ios::out) clears old file
    ofstream out(FILENAME, ios::binary);
    if (!out) {
        cout << "Cannot open file for writing.\n";
        return;
    }

    // write() needs bytes (char*). We convert the address of each struct
    // using a simple C-style cast (char*)&arr[i]
    for (int i = 0; i < 3; ++i) {
        out.write((char*)&arr[i], sizeof(Student));
        cout << "Written: " << arr[i].name << " (" << arr[i].roll << ")\n";
    }
    out.close();
    cout << "\nInitial records saved.\n";
}

// Find by roll number (linear search)
void searchByRoll() {
    cout << "\nEnter roll number to search: ";
    int target;
    if (!(cin >> target)) {
        cout << "Invalid number.\n";
        cin.clear();
        return;
    }

    ifstream in(FILENAME, ios::binary);
    if (!in) {
        cout << "Cannot open file for reading.\n";
        return;
    }

    Student s;
    bool found = false;

    // Read one struct at a time until EOF
    while (in.read((char*)&s, sizeof(Student))) {
        if (s.roll == target) {
            cout << "Record found:\n";
            showStudent(s);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No record with roll " << target << ".\n";
    }
    in.close();
}

// Find by position (0 = first, 1 = second, etc.)
void searchByPosition() {
    cout << "\nEnter position (0, 1, or 2): ";
    int pos;
    if (!(cin >> pos)) {
        cout << "Invalid number.\n";
        cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (pos < 0 || pos >= 3) {
        cout << "Position out of range.\n";
        return;
    }

    ifstream in(FILENAME, ios::binary);
    if (!in) {
        cout << "Cannot open file for reading.\n";
        return;
    }

    // Jump directly to the bytes of the desired record
    long offset = pos * (long)sizeof(Student);
    in.seekg(offset);

    Student s;
    if (in.read((char*)&s, sizeof(Student))) {
        cout << "Record at position " << pos << ":\n";
        showStudent(s);
    } else {
        cout << "Could not read record.\n";
    }

    in.close();
}

int main() {
    createRecords();

    // Clear leftover newline before next numeric input (optional safety)
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    searchByRoll();

    cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    searchByPosition();

    cout << "\nDone. Data stored in " << FILENAME << "\n";
    return 0;
}
