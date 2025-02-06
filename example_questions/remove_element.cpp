/*Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores). */

#include <vector>

int removeElement(vector<int>& nums, int val) {
    int i = 0; // Slow pointer
    for (int j = 0; j < nums.size(); j++) { // Fast pointer
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
