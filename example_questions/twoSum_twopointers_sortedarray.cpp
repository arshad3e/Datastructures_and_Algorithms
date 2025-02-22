/*add proper question*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int k){

    int left = nums[0];
    int right = nums.size()-1;

    for(int i=0; i<nums.size();i++){

        int sum = nums[left]+nums[right];

        if(sum == k){
            return {left,right};
        }
        else if(sum > k){
            right--;
        }
        else{
            left++;
        }
    }
    return {};
}

int main(){

    vector<int> nums ={1,2,3,4,5,6,7,8};

    vector<int> indices = twoSum(nums,7);

    cout << indices[0] << indices[1] <<endl;

    return 0;
}

/*Step-by-Step Execution
Step 1: Initialize answer
cpp
Copy
Edit
vector<int> answer(n, 1);
We create answer as [1, 1, 1, 1] (since multiplication starts with 1).

Step 2: Compute Prefix Products
Iteration 1:
i = 0, prefix = 1
Store answer[0] = prefix = 1
Update prefix = 1 * nums[0] = 1
Iteration 2:
i = 1, prefix = 1
Store answer[1] = prefix = 1
Update prefix = 1 * nums[1] = 2
Iteration 3:
i = 2, prefix = 2
Store answer[2] = prefix = 2
Update prefix = 2 * nums[2] = 6
Iteration 4:
i = 3, prefix = 6
Store answer[3] = prefix = 6
Update prefix = 6 * nums[3] = 24
✅ After prefix pass, answer = [1, 1, 2, 6]

Step 3: Compute Suffix Products
Iteration 1:
i = 3, suffix = 1
Multiply: answer[3] *= suffix → answer[3] = 6 * 1 = 6
Update suffix = 1 * nums[3] = 4
Iteration 2:
i = 2, suffix = 4
Multiply: answer[2] *= suffix → answer[2] = 2 * 4 = 8
Update suffix = 4 * nums[2] = 12
Iteration 3:
i = 1, suffix = 12
Multiply: answer[1] *= suffix → answer[1] = 1 * 12 = 12
Update suffix = 12 * nums[1] = 24
Iteration 4:
i = 0, suffix = 24
Multiply: answer[0] *= suffix → answer[0] = 1 * 24 = 24
Update suffix = 24 * nums[0] = 24
✅ Final answer = [24, 12, 8, 6]*/
