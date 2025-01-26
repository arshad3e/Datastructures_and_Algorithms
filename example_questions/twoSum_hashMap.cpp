#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;   // Step 1: Create a hash map to store numbers and their indices
    for (int i = 0; i < nums.size(); i++) {  // Step 2: Loop through the array
        int complement = target - nums[i];   // Step 3: Calculate the complement of the current number
        if (map.find(complement) != map.end()) {  // Step 4: Check if the complement exists in the hash map
            return {map[complement], i};  // Step 5: If it exists, return the indices
        }
        map[nums[i]] = i;  // Step 6: Store the current number and its index in the hash map
    }
    return {};  // Step 7: If no solution is found (not applicable in this problem)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    return 0;
}
