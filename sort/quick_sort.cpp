#include <iostream>
using namespace std;

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to arrange elements around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // If current element is less than pivot
            i++;               // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted Array: ";
    printArray(arr, n);
    return 0;
}



/* Quick Sort Logic:
Choose a Pivot:

Quick Sort works by selecting a "pivot" element from the array. The choice of pivot can vary, but a common choice is the last element in the array segment being sorted.
Partition the Array:

Rearrange the elements in the array so that all elements less than the pivot are on the left, and all elements greater than the pivot are on the right.
After this step, the pivot is in its final position in the sorted array.
Recursively Apply Quick Sort:

Apply the same logic recursively to the subarrays of elements to the left and right of the pivot.
Example Walkthrough:
Let's walk through a step-by-step example to understand how Quick Sort works. Consider the array:

css
Copy code
arr = [10, 7, 8, 9, 1, 5]
Initial Array: [10, 7, 8, 9, 1, 5]

Choosing the Pivot:

Select the last element as the pivot: pivot = 5.
Partitioning:

Rearrange the array so elements less than 5 are on the left, and elements greater than 5 are on the right.

Starting with i = -1:

Compare each element with the pivot (5).
Swap elements as needed to keep elements smaller than 5 on the left.
After partitioning with 5 as pivot:

csharp
Copy code
[1, 5, 8, 9, 10, 7]
The array is split around 5, which is now in its sorted position at index 1.

Recursive Steps:

Repeat the process for the subarrays [1] (left of pivot) and [8, 9, 10, 7] (right of pivot).

Continue partitioning and recursively applying Quick Sort until the array is sorted.*/
