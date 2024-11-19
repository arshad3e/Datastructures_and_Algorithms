/* This program is based on the sorting algorithm called MergeSort
This algorithm is based on the divide and concur approach
Time complexity = O(n log n)
Space Complexity = O(n)
*/

#include <iostream>
using namespace std;

// Merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    int L[n1], R[n2];        // Temporary arrays

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the left half
        mergeSort(arr, left, mid);

        // Sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    int arr[] = {6, 3, 8, 5, 2, 7, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(arr, size);

    return 0;
}

/* 
Merge Sort is a Divide and Conquer algorithm:

Divide: Split the array into two halves until each part contains a single element.
Conquer: Recursively sort each half.
Combine: Merge the sorted halves into a single sorted array.
Key Idea
Break the array into smaller parts.
Merge two sorted arrays into one sorted array during the merging phase.
Example: Sorting [6, 3, 8, 5, 2, 7, 4, 1]
Initial Array
csharp
Copy code
[6, 3, 8, 5, 2, 7, 4, 1]
Step-by-Step Process
Divide the Array:

Split into two halves:
less
Copy code
Left: [6, 3, 8, 5]
Right: [2, 7, 4, 1]
Divide Again:

Split [6, 3, 8, 5] into [6, 3] and [8, 5].
Split [2, 7, 4, 1] into [2, 7] and [4, 1].
Divide Further Until Single Elements:

[6, 3] becomes [6] and [3].
[8, 5] becomes [8] and [5].
[2, 7] becomes [2] and [7].
[4, 1] becomes [4] and [1].
Merge and Sort:

Merge [6] and [3] → [3, 6].
Merge [8] and [5] → [5, 8].
Merge [2] and [7] → [2, 7].
Merge [4] and [1] → [1, 4].
Merge Larger Sorted Arrays:

Merge [3, 6] and [5, 8] → [3, 5, 6, 8].
Merge [2, 7] and [1, 4] → [1, 2, 4, 7].
Final Merge:

Merge [3, 5, 6, 8] and [1, 2, 4, 7] → [1, 2, 3, 4, 5, 6, 7, 8].
Visual Breakdown of the Process
Splitting Phase:
css
Copy code
[6, 3, 8, 5, 2, 7, 4, 1]
           /                \
     [6, 3, 8, 5]       [2, 7, 4, 1]
       /     \            /      \
   [6, 3]   [8, 5]    [2, 7]   [4, 1]
    / \       / \       / \      / \
  [6] [3]   [8] [5]   [2] [7]  [4] [1]
Merging Phase:
Merge [6] and [3] → [3, 6]
Merge [8] and [5] → [5, 8]
Merge [2] and [7] → [2, 7]
Merge [4] and [1] → [1, 4]
css
Copy code
[3, 6]   [5, 8]   [2, 7]   [1, 4]
Merge [3, 6] and [5, 8] → [3, 5, 6, 8]
Merge [2, 7] and [1, 4] → [1, 2, 4, 7]
css
Copy code
[3, 5, 6, 8]   [1, 2, 4, 7]
Merge [3, 5, 6, 8] and [1, 2, 4, 7] → [1, 2, 3, 4, 5, 6, 7, 8]
*/
