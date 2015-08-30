#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void combinationSumUtil(vector<vector<int> > &csum
							,vector<int> nums
							,vector<int> A,int pos,int target){

		if(target == 0){
			//if(find(csum.begin(),csum.end(),nums)==csum.end())
			csum.push_back(nums);
			return;
		}
		int l = A.size();
		for(int i=pos;i<A.size();i++){
			if(target < A[i])
				return;
			if(i > 0 && A[i] == A[i-1] && pos < i)
			    continue;
			nums.push_back(A[i]);
			combinationSumUtil(csum,nums,A,i+1,target-A[i]);
			nums.pop_back();

		}
		
	}

    vector<vector<int> > combinationSum(vector<int>& A, int B) {
        vector<vector<int> > csum;
        vector<int> nums;
        sort(A.begin(),A.end());
        combinationSumUtil(csum,nums,A,0,B);
        return csum;
    }
};

int main(){
	int a[] = {10,1,2,7,6,1,5};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+l);
	Solution s;
	vector<vector<int> > csum = s.combinationSum(v,8);
	for(int i=0;i<csum.size();i++){
		for(int j=0;j<csum[i].size();j++){
			cout<<csum[i][j]<<" ";
		}
		cout<<endl; 
	}
	return 0;
}