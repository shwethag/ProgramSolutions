#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:	
	int binarySearch(vector<int> &nums,int low,int high,int target){
		int mid;
		while(low<=high){
			mid = low + (high-low)/2;
			if(nums[mid] == target)
				return mid;
			if(nums[mid] > target)
				high = mid-1;
			else
				low = mid + 1;
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if(len == 0)
			return -1;
        int low = 0;
        int high = len-1,mid;
		int next,prev;    
		int pivot=0;    
        while(low<=high){
        	mid = low + (high-low)/2;
        	prev = (mid-1+len)%len;
        	next = (mid + 1)%len;
        	if(nums[mid]<nums[prev] && nums[mid]<nums[next])
        	{
        		pivot = mid;
        		break;
        	}
        	if(nums[mid]>nums[high])
        		low = mid+1;
        	else
        		high = mid-1;

        }
       // cout<<"pivot "<<nums[pivot]<<endl;
        if(target >= nums[0]){
        	high = (pivot-1+len)%len;
        	//cout<<"h:"<<high<<endl;
        	return binarySearch(nums,0,high,target);
        }else{
        	return binarySearch(nums,pivot,len-1,target);
        }
        return -1;
       
    }
};

int main(){
	int a[] = {4,5,6,7,8,1,2};
	int len = sizeof(a)/sizeof(a[0]);
	cout<<len<<endl;
	vector<int> nums(a,a+len);
	Solution s;
	for(int i=0;i<=8;i++)
		cout<<i<<" " <<s.search(nums,i)<<endl;	
	return 0;
}

