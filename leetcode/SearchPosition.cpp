#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1,mid; 
        while(l <= h){
        	mid = ceil((l+h)/2.0);
        	if(nums[mid] == target)
        		return mid;
        	if(nums[mid] < target){
        		l = mid+1;
        	}else{
        		h = mid -1;
        	}
        }
        if(target < nums[mid] )
            return mid;
        return mid+1;
    }
};

int main(){
	
	Solution s;

	int arr[] = {1,3,5,6};
	vector<int> nums(arr,arr+4);

	cout<<s.searchInsert(nums,5)<<endl;
	cout<<s.searchInsert(nums,2)<<endl;
	cout<<s.searchInsert(nums,7)<<endl;
	cout<<s.searchInsert(nums,0)<<endl;



	return 0;
}