

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
