#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int> > threeSum(vector<int>& A) {
    	vector<vector<int> > tsum;
    	int len = A.size();
    	if(len < 3)
    		return tsum;
    	sort(A.begin(),A.end());

        
        int st,end,sum,sz;
        for(int i=0;i<len;i++){
        	if(i > 0 && A[i] == A[i-1])
        		continue;

        	st = i+1,end = len-1;

        	while(st<end){
        		sum = A[i] + A[st] + A[end];
        		if(sum == 0){
        			vector<int> sol;
        			sol.push_back(A[i]);
        			sol.push_back(A[st]);
        			sol.push_back(A[end]);
        			tsum.push_back(sol);
        			st++;
        			end--;

        			while(st < end && A[st] == A[st-1])
        				st++;
        			while(st < end && A[end] == A[end+1])
        				end--;
        		}
        		else if(sum > 0){
        			end--;
        			while(st < end && A[end] == A[end+1])
        				end--;
        		}
        		else{
        			st++;
        			while(st < end && A[st] == A[st-1])
        				st++;
        		}

        	}
        }
        return tsum;
    }
};

int main(){

	int a[]= {-1,0 ,1 ,2,-1, -1,-4};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> nums(a,a+l);

	Solution s;
	vector<vector<int> > sum3 = s.threeSum(nums);
	for(int i=0;i<sum3.size();i++){
		for(int j=0;j<sum3[i].size();j++){
			cout<<sum3[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}