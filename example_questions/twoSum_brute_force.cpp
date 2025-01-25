#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum(vector<int>& num_list, int value){
	int n = num_list.size(); //outer loop to iterate over the array
	for(int i=0; i<n ; i++){     //inner loop to calculate the actual sum
		for(int j=i+1; j<n ;j++){
			if( num_list[i] + num_list[j] == value){
				return {i,j};
			}
		}
	}
return {};
}

int main(){

	vector<int> num_list = {2,7,11,23};
	int target = 9;
	vector<int> result = two_sum(num_list,target);
	cout << "Indicies are" << result[0] << result [1] << endl;
return 0;

}

/* Brute Force Approach
Logic: Check all pairs of elements to find the pair that sums up to the target.
Time Complexity: 
𝑂(𝑛2) as we are using nested loops.
Space Complexity: 
𝑂(1), as no extra space is used. */
