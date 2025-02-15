#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int dest = nums.size() - 1; // Last index
    int count = 0, max_reach = 0, curr_end = 0;

    for (int i = 0; i < dest; i++) {
        max_reach = max(max_reach, i + nums[i]); // Update farthest reach

        if (i == curr_end) { // If we reach the current boundary, we must jump
            count++;
            curr_end = max_reach;

            if (curr_end >= dest) return count; // If we reach last index, return
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 1, 1, 1};
    cout << "Minimum jumps: " << jump(nums) << endl; // Output: 3
    return 0;
}
