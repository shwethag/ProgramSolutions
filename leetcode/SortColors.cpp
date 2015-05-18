#include <iostream>
#include <vector>

using namespace std;

/*
 Given an array with n objects colored red, white or blue, 
 sort them so that objects of the same color are adjacent,
 with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, 
then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hash[3]={0};
        int len = nums.size();
        for(int i=0;i<len;i++){
        	hash[nums[i]]++;
        }
        int j=0;
        for(int i=0;i<3;i++){
        	while(hash[i]){
        		nums[j] = i;
        		hash[i]--;
        		j++;
        	}
        }
    }
};

int main(){

	int a[] = {0,1,2,0,0,1,2,2,0,1,2,1,2,2,2,1,1,0,2,0,1,1,0,0,2,1};
	vector<int> nums(a,a+26);
	Solution s;
	s.sortColors(nums);
	int len = nums.size();
	for(int i=0;i<len;i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}