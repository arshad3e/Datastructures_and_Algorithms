#include <iostream>
#include <vector>
using namespace std;

int subArray_sum(vector<int>& nums, int k){
    int count=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i; j<n ; j++){
            sum = sum + nums[j];
            if(sum == k){
                count ++;
            }
        }
    }
    return count;
}

int main(){

    vector<int> nums = {1,1,1};
    int k = 2;

    int final_value = subArray_sum(nums,k);

    cout << "Final number of subset array" << final_value << endl;

    return 0;
}