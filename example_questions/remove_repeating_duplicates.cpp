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

/*

The problem asks you to remove duplicate elements from a sorted array nums in-place.  You should return the number of unique elements (k), and the first k elements of nums should contain those unique elements in their original order.  The elements beyond the first k are irrelevant.

Here's an efficient approach using two pointers:

i (Slow Pointer): This pointer keeps track of the position where the next unique element should be placed. It starts at 0.

j (Fast Pointer): This pointer iterates through the array from the beginning to the end. It starts at 1 (because the first element is always considered unique).

Iterate and Check: Loop through the array using the fast pointer j:

If nums[j] is different from nums[j - 1] (meaning you've encountered a new unique element):
Copy nums[j] to nums[i].
Increment i (because you've just placed a unique element).
Increment j in every iteration (to move to the next element).
Return i: After the loop finishes, i will be equal to the number of unique elements. Return i.

Example (using your Example 1):

nums = [1, 1, 2]

i = 0, j = 1
nums[1] (1) == nums[0] (1): j++
nums[2] (2) != nums[1] (1): nums[0] = nums[2] (2), i++, j++
Loop finishes. Return i (which is 2). nums is now [2, 2, 2] (or [2, 2, _] - the values beyond the returned k don't matter). The first two elements are 1 and 2, which are the unique elements.

*/
