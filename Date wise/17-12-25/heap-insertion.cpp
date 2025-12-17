/**
 * Heap Insertion in C++
 */

#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int>& heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void insertIntoHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> maxHeap;

    insertIntoHeap(maxHeap, 10);
    insertIntoHeap(maxHeap, 20);
    insertIntoHeap(maxHeap, 5);
    insertIntoHeap(maxHeap, 30);
    insertIntoHeap(maxHeap, 15);

    cout << "Max Heap after insertions: ";
    printHeap(maxHeap);

    return 0;
}