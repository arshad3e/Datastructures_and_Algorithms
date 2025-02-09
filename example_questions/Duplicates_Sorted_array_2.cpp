int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();  // No need to process small arrays

    int i = 2;  // Start from the third element since the first two are always valid

    for (int j = 2; j < nums.size(); j++) {
        // Keep nums[j] if it's different from nums[i - 2]
        if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

/*Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
