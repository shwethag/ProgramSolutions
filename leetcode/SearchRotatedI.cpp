#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:	
	bool binarySearch(vector<int> &nums,int low,int high,int target){
		int mid;
		while(low<=high){
			mid = low + (high-low)/2;
			if(nums[mid] == target)
				return true;
			if(nums[mid] > target)
				high = mid-1;
			else
				low = mid + 1;
		}
		return false;
	}

	int findPivot(vector<int> &nums,int low,int high ){
		int mid;
		//high < low
		if(high < low)
			return 0;

		//high == low
		if(high == low)
			return low;

		mid = low + (high-low)/2;
		//cout<<low<<" "<<mid<<" "<<high<<endl;
		//mid < high and a[mid+1]<a[mid]
		if(mid < high && nums[mid+1] < nums[mid])
			return mid+1;

		//a[mid]==a[low]==a[high] search both sides and get min
		if(nums[mid] == nums[low] && nums[mid] == nums[high]){
			int i1 = findPivot(nums,low,mid-1);
			int i2 = findPivot(nums,mid+1,high);
			cout<<i1<<" "<<i2<<endl;
			if(nums[i1]<=nums[i2])
				return i1;
			else
				return i2;
		}

		//mid > low and a[mid-1]>a[mid]
		if(mid > low && nums[mid-1]>nums[mid])
			return mid;

		//a[high] > a[mid] -search lower half else higher half
		if(nums[high] >= nums[mid]){
			return findPivot(nums,low,mid-1);
		}else{
			return findPivot(nums,mid+1,high);
		}

	}

	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if(len == 0)
			return -1;
        int pivot = findPivot(nums,0,len-1);
       	cout<<"pivot "<<nums[pivot]<<" "<<pivot <<endl;
       	if(nums[0] == nums[len-1]){
       		int high = (pivot-1+len)%len;
       		cout<<"l r eq "<<high<<endl;
       		int ret =  binarySearch(nums,0,high,target);
       		if(!ret)
       		{
       			ret = binarySearch(nums,pivot,len-1,target);
       		}
       		return ret;
       	}
        else if(target > nums[len-1]){
        	int high = (pivot-1+len)%len;
        	//cout<<"h: "<<high<<endl;
        	return binarySearch(nums,0,high,target);
        }else{
        	return binarySearch(nums,pivot,len-1,target);
        }
        return false;
       
    }
};

int main(){
	int a[] = {1,3,1,1,1,1};
	int len = sizeof(a)/sizeof(a[0]);
	cout<<len<<endl;
	vector<int> nums(a,a+len);
	Solution s;
	/*for(int i=0;i<=8;i++)
		cout<<i<<" " <<s.search(nums,i)<<endl;*/
	cout<<s.search(nums,3)<<endl;
	return 0;
}

