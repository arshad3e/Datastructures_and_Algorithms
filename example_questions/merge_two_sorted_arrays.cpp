#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;      // Index for nums1
    int j = n - 1;      // Index for nums2
    int k = m + n - 1;  // Index for merged array in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy any remaining elements from nums2
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "[";
    for (int val : nums1) {
        cout << val << ", ";
    }
    cout << "\b\b]" << endl; // Output: [1, 2, 2, 3, 5, 6]


    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    merge(nums1, m, nums2, n);
    cout << "[";
    for (int val : nums1) {
        cout << val << ", ";
    }
    cout << "\b\b]" << endl; // Output: [1]

    nums1 = {1};
    m = 1;
    nums2 = {};
    n = 0;
    merge(nums1, m, nums2, n);
    cout << "[";
    for (int val : nums1) {
        cout << val << ", ";
    }
    cout << "\b\b]" << endl; // Output: [1]

    nums1 = {2,0};
    m = 1;
    nums2 = {1};
    n = 1;
    merge(nums1, m, nums2, n);
    cout << "[";
    for (int val : nums1) {
        cout << val << ", ";
    }
    cout << "\b\b]" << endl; // Output: [1, 2]

    return 0;
}

/* Key Changes and Explanations (C++ version):

std::vector: Uses std::vector to represent the dynamic arrays. This is the standard way to work with arrays that can resize in C++.
Pass by Reference: The merge function takes nums1 and nums2 by reference (vector<int>&). This is crucial because you need to modify nums1 directly (in-place).
Includes: The <iostream> header is included for input/output (like cout), and <vector> is included for using std::vector.
Output: The main function now prints the contents of the merged nums1 vector using a range-based for loop, which is a clean way to iterate over the elements of a vector. The \b\b is used to remove the trailing comma and space from the output.
Example Usages: Just like the Python version, I've added a few example usages to demonstrate the function's behavior, including your test case and edge cases.
The logic of the merge function itself is identical to the Python version. The core idea of using three pointers and merging from the end remains the same.  The only differences are related to the syntax and how arrays are handled in C++.*/
