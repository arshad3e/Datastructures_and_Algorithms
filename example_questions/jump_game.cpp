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
