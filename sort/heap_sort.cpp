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

/*
What is Heap Sort?
Heap Sort is a comparison-based sorting algorithm that uses a binary heap to organize and sort data. It involves two main steps:

Build a Max Heap:

Convert the input array into a Max Heap, where the largest element is the root.
Sort the Array:

Repeatedly extract the root (largest element) and place it at the end of the array.
Rebuild the heap to maintain the Max Heap property after each extraction.
Key Idea
Heap Sort uses the heap data structure to efficiently find and sort the largest elements. A Max Heap ensures the largest element is always at the root, making sorting straightforward.

Example: Sorting [4, 10, 3, 5, 1]
Initial Array
csharp
Copy code
[4, 10, 3, 5, 1]
Step-by-Step Process
Step 1: Build a Max Heap
Start from the last non-leaf node and heapify the array.

The last non-leaf node is at index (n/2) - 1, where n is the array size.
Heapify each subtree:

Heapify means rearranging the subtree to ensure the largest element is at the root.
Heapify Process:

Start with [4, 10, 3, 5, 1]:

Consider node at index 1 (10):
Left child = 5, right child = 1. 10 is already the largest.
No changes needed.
Now, move to the root node (index 0):

Node = 4, left child = 10, right child = 3.

Swap 4 and 10 because 10 > 4:

csharp
Copy code
[10, 4, 3, 5, 1]
Now, heapify the subtree rooted at index 1:

Node = 4, left child = 5, right child = 1.
Swap 4 and 5 because 5 > 4:
csharp
Copy code
[10, 5, 3, 4, 1]
The array is now a Max Heap:

csharp
Copy code
[10, 5, 3, 4, 1]
Step 2: Sort the Array
Swap the root (10) with the last element:

csharp
Copy code
[1, 5, 3, 4, 10]
Reduce the heap size by 1 (ignore the sorted portion) and rebuild the heap:

Root = 1, left child = 5, right child = 3.

Swap 1 and 5 because 5 > 1:

csharp
Copy code
[5, 1, 3, 4, 10]
Heapify the subtree rooted at index 1:

Node = 1, left child = 4.
Swap 1 and 4 because 4 > 1:
csharp
Copy code
[5, 4, 3, 1, 10]
Swap the root (5) with the last unsorted element:

csharp
Copy code
[1, 4, 3, 5, 10]
Rebuild the heap:

Root = 1, left child = 4, right child = 3.
Swap 1 and 4 because 4 > 1:
csharp
Copy code
[4, 1, 3, 5, 10]
Swap the root (4) with the last unsorted element:

csharp
Copy code
[3, 1, 4, 5, 10]
Rebuild the heap:

Root = 3, left child = 1.
No swaps needed.
Swap the root (3) with the last unsorted element:

csharp
Copy code
[1, 3, 4, 5, 10]
Final Sorted Array
csharp
Copy code
[1, 3, 4, 5, 10] 
Time Complexity
Best, Worst, and Average Case: O(n log n) (heapify is O(log n) and repeated n times).
Space Complexity: O(1) (in-place sorting).
*/
