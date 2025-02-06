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
