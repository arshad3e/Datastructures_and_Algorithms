#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot is the last element
    int i = low - 1;       // Index for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in the correct position
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
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


/* What is Quick Sort?
Quick Sort is a Divide and Conquer algorithm, where:

Pick a Pivot:

Choose a pivot element from the array. Common choices include:
First element.
Last element.
Random element.
Middle element.
Partition the Array:

Rearrange the elements so that all elements smaller than the pivot are placed on its left and all elements greater than the pivot are placed on its right.
Recursively Apply Quick Sort:

Apply the same steps to the left and right subarrays (excluding the pivot, which is already in its final position).
Key Idea
The pivot helps divide the array into smaller, easier-to-sort subarrays. By repeatedly applying this process, the array becomes sorted.

Example: Sorting [10, 7, 8, 9, 1, 5]
Initial Array
csharp
Copy code
[10, 7, 8, 9, 1, 5]
Step-by-Step Process
Choose the Pivot:

Let’s pick the last element as the pivot: pivot = 5.
Partition the Array:

Rearrange elements around the pivot so:
Elements smaller than 5 are on the left.
Elements greater than 5 are on the right.
Partition Process:

Start with i = -1 (to track the boundary of smaller elements).
Iterate through the array with j (current element index):
If arr[j] < pivot, increment i and swap arr[i] with arr[j].
Steps:

vbnet
Copy code
[10, 7, 8, 9, 1, 5]  (Initial array, pivot = 5)

Compare 10 with 5: No swap, i = -1
Compare 7 with 5: No swap, i = -1
Compare 8 with 5: No swap, i = -1
Compare 9 with 5: No swap, i = -1
Compare 1 with 5: Swap 1 with 10 → [1, 7, 8, 9, 10, 5], i = 0
After the loop, place the pivot 5 in its correct position by swapping it with arr[i + 1]:

csharp
Copy code
[1, 5, 8, 9, 10, 7]  (Pivot 5 is now in position 1)
Now, the pivot 5 is sorted, and the array is divided into:

Left: [1] (elements smaller than 5)
Right: [8, 9, 10, 7] (elements greater than 5).
Recursive Steps:

Left Subarray: [1] (already sorted).

Right Subarray: [8, 9, 10, 7]

Pivot = 7.
Partitioning:
vbnet
Copy code
[8, 9, 10, 7]  (Pivot = 7)
Compare 8 with 7: No swap, i = 0
Compare 9 with 7: No swap, i = 0
Compare 10 with 7: No swap, i = 0
Swap 7 with 8 → [7, 9, 10, 8] (Pivot 7 in position 0)
Now:
Left: [] (no elements smaller than 7).
Right: [9, 10, 8].
Continue recursively sorting [9, 10, 8]:

Pivot = 8.
Partitioning:
vbnet
Copy code
[9, 10, 8]  (Pivot = 8)
Compare 9 with 8: No swap, i = 0
Compare 10 with 8: No swap, i = 0
Swap 8 with 9 → [8, 10, 9] (Pivot 8 in position 0)
Now:
Left: [].
Right: [10, 9].
Sort [10, 9]:

Pivot = 9.
Partitioning:
csharp
Copy code
[10, 9]  (Pivot = 9)
Compare 10 with 9: No swap, i = 0
Swap 9 with 10 → [9, 10] (Pivot 9 in position 0)
Now the array is fully sorted:
csharp
Copy code
[1, 5, 7, 8, 9, 10] */
