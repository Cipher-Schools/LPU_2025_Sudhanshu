#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Min-Heap using STL
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements
    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(30);
    minHeap.push(5);
    minHeap.push(20);

    cout << "Top (Minimum): " << minHeap.top() << endl;

    // Remove elements
    cout << "Extracting elements in sorted order:\n";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
