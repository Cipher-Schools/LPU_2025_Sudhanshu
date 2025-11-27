/**
 * Program to demonstrate the usage of STL priority queue in C++
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Create a max-heap priority queue
    priority_queue<int> maxHeap;

    // Insert elements into the max-heap
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.push(15);

    cout << "Max-Heap Priority Queue:" << endl;
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Print the top element
        maxHeap.pop();                // Remove the top element
    }
    cout << endl;

    // Create a min-heap priority queue using greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min-heap
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(15);

    cout << "Min-Heap Priority Queue:" << endl;
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Print the top element
        minHeap.pop();                 // Remove the top element
    }
    cout << endl;

    return 0;
}