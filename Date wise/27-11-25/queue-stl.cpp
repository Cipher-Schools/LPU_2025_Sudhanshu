/**
 * Program to demonstrate the usage of STL queue in C++
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front element
    cout << "Front element: " << q.front() << endl;

    // Display the size of the queue
    cout << "Queue size: " << q.size() << endl;

    // Remove elements from the queue
    cout << "Removing elements from the queue:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Final size of the queue
    cout << "Final queue size: " << q.size() << endl;

    return 0;
}