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
