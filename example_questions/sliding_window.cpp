#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSubarray(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        cout << "Invalid input: k is larger than the array size." << endl;
        return -1;
    }

    int maxSum = INT_MIN;
    int currentSum = 0;

    // Initial window sum for the first k elements
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }

    maxSum = currentSum;

    // Slide the window over the array
    for (int i = k; i < n; i++) {
        currentSum += nums[i] - nums[i - k];  // Add new element, remove the first element of the previous window
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSumSubarray(nums, k);
    cout << "Maximum sum of a subarray of size " << k << " is: " << result << endl;

    return 0;
}

/* Example Walkthrough
Given nums = [2, 1, 5, 1, 3, 2] and k = 3:

Initial sum of the first window [2, 1, 5]: 2 + 1 + 5 = 8
Slide the window: [1, 5, 1]: 8 - 2 + 1 = 7
Slide again: [5, 1, 3]: 7 - 1 + 3 = 9
Slide again: [1, 3, 2]: 9 - 5 + 2 = 6
The maximum sum is 9. */
