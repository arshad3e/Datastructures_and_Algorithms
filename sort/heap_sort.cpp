#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with the largest
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build a Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to the end
        heapify(arr, i, 0);   // Heapify the reduced heap
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
