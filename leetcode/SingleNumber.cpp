#include <iostream>
#include <vector>

using namespace std;
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int len = nums.size();
    	int num = 0;
    	for(int i=0;i<len;i++){
    		num = num ^ nums[i];
    	}
    	return num;
        
    }
};

int main(){
	int arr[]={2,4,3,3,2};
	vector<int> nums(arr,arr+5);
	Solution s;
	cout<<s.singleNumber(nums)<<endl;

	return 0;
}
