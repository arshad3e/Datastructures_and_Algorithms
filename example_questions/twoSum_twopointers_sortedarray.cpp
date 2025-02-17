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
