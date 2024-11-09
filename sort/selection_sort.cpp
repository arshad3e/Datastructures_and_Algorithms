/*Selection sort for example (9,8,7,6) we will select 9 as min_index and then compare with 8,7,6 since it is greater than 6 it is swapped and 6,8,7,9
time complexity of o(n^2)*/

#include<iostream>
using namespace std;

/* logic to support swapping*/
void swap(int *num1, int *num2){
        int temp =0;
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
}

void selection_sort(int arr[], int n){
        for(int i=0; i<n-1; i++){  //main loop that goes through all the elements
        int min_index = i;
                for(int j=i+1; j<n;j++){ //loop where it goes through all the elements to find the smallest of all before swapping
                        if(arr[j] < arr[min_index]){
                                min_index = j;
                        }
                        if(min_index !=i){ // once smallest is found will be swapped with the current index
                                swap(&arr[min_index], &arr[i]);
                        }
                        }
}}

int main(){

        int arr[] = {9,8,7,6,5,4};
        int siz = sizeof(arr)/sizeof(arr[0]);
        selection_sort(arr,siz);
        for(int i=0; i<siz; i++){
                cout << arr[i] << " " ;
        }
        return 0;
}

/*
Consider this array as an example: arr = {64, 25, 12, 22, 11} and n = 5 (size of the array).

cpp
Copy code
void selection_sort(int arr[], int n) {
Function Declaration: This function selection_sort takes an array of integers arr and an integer n (the size of the array).
cpp
Copy code
    for (int i = 0; i < n - 1; i++) {
Outer Loop: The outer loop runs from the start of the array up to the second last element (n - 1).
Purpose: Each iteration of this loop places the smallest remaining unsorted element in its correct position.
Step-by-Step Execution with the Example:
First Iteration (i = 0):

We are starting from index 0, assuming arr[0] (64) is the smallest in the remaining array.
cpp
Copy code
     int min_index = i;
Initialize min_index: We assume the first element in the remaining unsorted part (index i) is the minimum.
Here, min_index = 0.
cpp
Copy code
     for (int j = i + 1; j < n; j++) {
Inner Loop: The inner loop starts from the next element (i + 1) and iterates to the end of the array to find the actual minimum element.
Find the Minimum in the Remaining Array:

For j = 1 (arr[1] = 25): 25 < 64, so min_index is updated to 1.

For j = 2 (arr[2] = 12): 12 < 25, so min_index is updated to 2.

For j = 3 (arr[3] = 22): 22 > 12, min_index remains 2.

For j = 4 (arr[4] = 11): 11 < 12, so min_index is updated to 4.

After the inner loop ends, the minimum value in the unsorted array is 11 at index 4.

Swap if Minimum is Not in the Correct Position:

cpp
Copy code
     if (min_index != i) {
         swap(&arr[min_index], &arr[i]);
     }
Condition Check: If the minimum index found (min_index) is not equal to the current position (i), we swap arr[i] and arr[min_index].
Since min_index = 4, we swap arr[0] with arr[4].
Array After Swap: {11, 25, 12, 22, 64}.
Second Iteration (i = 1):

Now, we repeat the process starting from index 1.

Initialize min_index = 1 (assuming arr[1] = 25 is the minimum).

Inner Loop:

For j = 2 (arr[2] = 12): 12 < 25, so min_index = 2.
For j = 3 (arr[3] = 22): 22 > 12, min_index remains 2.
For j = 4 (arr[4] = 64): 64 > 12, min_index remains 2.
After the inner loop, the minimum element is 12 at index 2.

Swap: arr[1] and arr[2] are swapped.

Array After Swap: {11, 12, 25, 22, 64}.

Third Iteration (i = 2):

Start from index 2, with min_index = 2 (assuming arr[2] = 25 is the minimum).

Inner Loop:

For j = 3 (arr[3] = 22): 22 < 25, so min_index = 3.
For j = 4 (arr[4] = 64): 64 > 22, min_index remains 3.
The minimum element in the remaining array is 22 at index 3.

Swap: arr[2] and arr[3] are swapped.

Array After Swap: {11, 12, 22, 25, 64}.

Fourth Iteration (i = 3):

Finally, start from index 3, with min_index = 3 (assuming arr[3] = 25 is the minimum).

Inner Loop:

For j = 4 (arr[4] = 64): 64 > 25, min_index remains 3.
Since min_index = 3, no swap is needed because 25 is already in the correct place.

Array After Swap: {11, 12, 22, 25, 64}.

Final Sorted Array:
After all iterations, the array is sorted as {11, 12, 22, 25, 64}.

Summary of Swaps:
Swap 64 and 11: {11, 25, 12, 22, 64}
Swap 25 and 12: {11, 12, 25, 22, 64}
Swap 25 and 22: {11, 12, 22, 25, 64}
Each step systematically places the next smallest element in its correct position, producing a sorted array.
        */
