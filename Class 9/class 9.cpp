#include <iostream>
#include <vector>
using namespace std;

// Function to up-heapify for Min-Heap
void upHeapifyMin(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parent]) {
        swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to up-heapify for Max-Heap
void upHeapifyMax(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to down-heapify for Min-Heap
void downHeapifyMin(vector<int>& heap, int index) {
    int size = heap.size();
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        downHeapifyMin(heap, smallest);
    }
}

// Function to down-heapify for Max-Heap
void downHeapifyMax(vector<int>& heap, int index) {
    int size = heap.size();
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        downHeapifyMax(heap, largest);
    }
}

// Function to delete the root (min or max) of the heap
void deleteRoot(vector<int>& heap, bool isMinHeap) {
    if (heap.size() == 0) {
        cout << "Heap is empty! Cannot delete root." << endl;
        return;
    }

    // Move the last element to the root
    heap[0] = heap.back();
    heap.pop_back();

    // Restore the heap property
    if (isMinHeap) {
        downHeapifyMin(heap, 0);
    } else {
        downHeapifyMax(heap, 0);
    }
}

int main() {
    vector<int> heap;
    int n, value, choice, heapType;

    cout << "Enter the number of elements in the heap: ";
    cin >> n;

    cout << "Choose heap type (1 for Min-Heap, 2 for Max-Heap): ";
    cin >> heapType;

    // Taking input for heap elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        heap.push_back(value);

        // Perform up-heapify based on heap type
        if (heapType == 1) {
            upHeapifyMin(heap, i);  // Min-Heap insert
        } else {
            upHeapifyMax(heap, i);  // Max-Heap insert
        }
    }

    // Display the current heap
    cout << (heapType == 1 ? "Min-Heap" : "Max-Heap") << " after insertion: ";
    for (int val : heap) cout << val << " ";
    cout << endl;

    // Ask if the user wants to delete the root
    cout << "Do you want to delete the root? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        deleteRoot(heap, heapType == 1);

        cout << (heapType == 1 ? "Min-Heap" : "Max-Heap") << " after deleting the root: ";
        for (int val : heap) cout << val << " ";
        cout << endl;
    }

    return 0;
}

