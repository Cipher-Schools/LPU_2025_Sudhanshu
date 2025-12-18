/**
 * Program to demonstrate the deletion in heap array data structure in C++.
 */

#include <iostream>
using namespace std;

// Function to delete an element from heap array
void deleteElement(int heap[], int &size) {
    if (size <= 0) {
        cout << "Heap is empty. Cannot delete element." << endl;
        return;
    }

    // Deleting the root element (for simplicity)
    cout << "Deleting element: " << heap[0] << endl;

    // Replace root with last element
    heap[0] = heap[size - 1];
    size--;

    // Heapify down from the root
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

int main() {
    // Creating a heap array
    int heap[] = {50, 30, 20, 15, 10, 8, 16};
    int size = sizeof(heap) / sizeof(heap[0]);

    cout << "Initial heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    // Deleting an element from the heap
    deleteElement(heap, size);

    cout << "Heap after deletion: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}