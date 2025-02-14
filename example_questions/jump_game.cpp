#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0; // Tracks the farthest index we can reach
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // If our reach is less than i, we are stuck
        maxReach = max(maxReach, i + nums[i]); // Update farthest reachable index
    }

    return true; // If we never got stuck, return true
}

int main() {
    vector<int> nums1 = {2,3,1,1,4};
    cout << (canJump(nums1) ? "true" : "false") << endl; // Output: true

    vector<int> nums2 = {3,2,1,0,4};
    cout << (canJump(nums2) ? "true" : "false") << endl; // Output: false

    return 0;
}

/*Explanation (Step-by-Step)
Example 1: nums = [2,3,1,1,4]
Index 0: Jump range = 0 + 2 = 2 → maxReach = 2
Index 1: Jump range = 1 + 3 = 4 → maxReach = 4
Index 2: Jump range = 2 + 1 = 3 (no change)
Index 3: Jump range = 3 + 1 = 4 (no change)
Index 4: Reached successfully → Return true
Example 2: nums = [3,2,1,0,4]
Index 0: Jump range = 0 + 3 = 3 → maxReach = 3
Index 1: Jump range = 1 + 2 = 3 (no change)
Index 2: Jump range = 2 + 1 = 3 (no change)
Index 3: Jump range = 3 + 0 = 3 (no change)
Index 4: Can't reach 4 since maxReach = 3 → Return false*/
