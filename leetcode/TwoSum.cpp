#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numhash;
        int len = nums.size();
        int diff;
        vector<int> indices;
        for(int i=0;i<len;i++){
            if(numhash[nums[i]]!=0){
                
                indices.push_back(numhash[nums[i]] );
                indices.push_back(i+1);
                return indices;
            }else{
            	diff = target - nums[i];
            	if(numhash[diff]==0)
            		numhash[diff] = i+1;
            }
        }
        return indices;
    }
};

int main(){
	int a[] = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+l);

	Solution s;
	vector<int> sum = s.twoSum(v,-3);

	cout<<sum[0]<<" "<<sum[1]<<endl;
	return 0;
}