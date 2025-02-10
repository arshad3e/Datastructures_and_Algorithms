#include <vector>
#include <iostream>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

/*How It Works
candidate: Tracks the current majority candidate.
count: Tracks the frequency balance for the candidate.
Loop:
Reset candidate if count becomes 0.
Increment or decrement count based on whether the element matches the candidate.
Example
Input: [2, 2, 1, 1, 1, 2, 2]
Output: 2

This is clean, efficient, and ready for coding interviews. Let me know if you want a further explanation!*/
