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

/* Step-by-Step Explanation
Step 1: Create a Hash Map
cpp
Copy
Edit
unordered_map<int, int> map;
The hash map (unordered_map) will store numbers as keys and their indices as values.
For example, if nums = [2, 7, 11, 15] and we’ve processed the number 2, the hash map would look like:
arduino
Copy
Edit
map = {2: 0}
This means "number 2 is at index 0."
Step 2: Loop Through the Array
cpp
Copy
Edit
for (int i = 0; i < nums.size(); i++) {
The loop iterates through each element in the array.
Variable i represents the current index.
Example: For nums = [2, 7, 11, 15], the loop processes:
nums[0] = 2
nums[1] = 7
nums[2] = 11
nums[3] = 15
Step 3: Calculate the Complement
cpp
Copy
Edit
int complement = target - nums[i];
The complement is the number that, when added to the current number, equals the target.
Formula:
css
Copy
Edit
complement = target - nums[i]
Example:
If target = 9 and nums[0] = 2, then:
makefile
Copy
Edit
complement = 9 - 2 = 7
The complement (7) is the number we need to find in the hash map.
Step 4: Check if the Complement Exists
cpp
Copy
Edit
if (map.find(complement) != map.end()) {
map.find(complement): This checks if the complement is already present in the hash map.
If the complement exists, it means we’ve already seen the number that pairs with the current number to form the target sum.
Example:
For nums = [2, 7, 11, 15] and target = 9:
On the second iteration (i = 1), the complement is 2.
Since 2 is already in the hash map (map = {2: 0}), we have found a solution.
Step 5: Return the Indices
cpp
Copy
Edit
return {map[complement], i};
If the complement is found in the hash map:
map[complement] gives the index of the complement.
i is the current index.
Example:
On the second iteration (i = 1):
complement = 2 is in the hash map at index 0.
Return the indices [0, 1].
Step 6: Store the Current Number
cpp
Copy
Edit
map[nums[i]] = i;
Add the current number and its index to the hash map.
This ensures the number is available as a potential complement in future iterations.
Example:
On the first iteration (i = 0), add 2 to the hash map:
arduino
Copy
Edit
map = {2: 0}
Step 7: Return Empty Vector
cpp
Copy
Edit
return {};
This is the fallback case if no solution exists. However, the problem guarantees a solution, so this line is never executed.
Dry Run Example
Let's walk through the code with nums = [2, 7, 11, 15] and target = 9.

Iteration	i	nums[i]	Complement	Hash Map Before	Action
1	0	2	7	{}	Add 2: 0 to hash map
2	1	7	2	{2: 0}	Complement 2 found, return [0, 1]
Final Hash Map
At the end of the second iteration, the hash map looks like this:
yaml
Copy
Edit
map = {2: 0, 7: 1}
The solution [0, 1] is returned because:
css
Copy
Edit
nums[0] + nums[1] = 2 + 7 = 9
Time and Space Complexity
Time Complexity:
Each number is processed once, and lookups in the hash map are 
𝑂
(
1
)
O(1).
Total: 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the size of the array.
Space Complexity:
The hash map requires 
𝑂
(
𝑛
)
O(n) space to store numbers and indices. */
