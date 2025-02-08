#include <vector>

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0; // Handle empty array case
    }
    int i = 0; // Slow pointer
    for (int j = 1; j < nums.size(); j++) { // Fast pointer
        if (nums[j] != nums[j - 1]) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
