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

/*Step-by-Step Execution for nums = [1, 2, 1, 1, 1]
Index	nums[i]	max_reach	curr_end	count	Action
0	1	max(0, 0+1) = 1	0	0	No jump yet
0 (Jump)	-	-	1	1	First jump
1	2	max(1, 1+2) = 3	1	1	No jump yet
1 (Jump)	-	-	3	2	Second jump
2	1	max(3, 2+1) = 3	3	2	No jump yet
3	1	max(3, 3+1) = 4	3	2	No jump yet
3 (Jump)	-	-	4	3	Third jump, reached last index ✅*/
