#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct. 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> hash;
        int len = nums.size();

        for(int i=0;i<len;i++){
        	if(hash[nums[i]])
        		return true;

        	hash[nums[i]] = true;
        }
        return false;
    }
};

int main(){

	Solution s;
	int a[] = {1,2,3,4,5};
	vector<int> nums(a,a+5);

	cout<<s.containsDuplicate(nums)<<endl;

	int b[] = {1,2,3,2,5};
	vector<int> nums2(b,b+5);

	cout<<s.containsDuplicate(nums2)<<endl;
	
	return 0;
}