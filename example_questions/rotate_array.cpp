#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;  // Handle cases where k >= n

    // Step 1: Reverse the entire array
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Step 2: Reverse the first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Step 3: Reverse the remaining elements
    for (int i = k, j = n - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    rotate(nums1, k1);
    cout << "Rotated Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    rotate(nums2, k2);
    cout << "Rotated Array: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*Explanation
Reverse Entire Array:
Swap elements from the start to the end.

Reverse First k Elements:
Swap elements from index 0 to k - 1.

Reverse Remaining Elements:
Swap elements from index k to n - 1.

Example Walkthrough
Input
ini
Copy
Edit
nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Process
Reverse entire array: [7, 6, 5, 4, 3, 2, 1]
Reverse first 3 elements: [5, 6, 7, 4, 3, 2, 1]
Reverse remaining elements: [5, 6, 7, 1, 2, 3, 4]
Complexity Analysis
Time Complexity: 
𝑂
(
𝑛
)
O(n)
Space Complexity: 
𝑂
(
1
)
O(1)
This version is compact, avoids helper functions, and performs efficiently.*/
