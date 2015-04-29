#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*
 Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is: 
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int len = S.size();
        int maxsubset = pow(2,len);
        vector<vector<int> > sols;
        for(int i=0;i<maxsubset;i++){
        	vector<int> set;
        	for(int j=0;j<len;j++){
        		if(i & (1<<j)){
        			set.push_back(S[j]);
        		}
        	}
        	sort(set.begin(),set.end());
        	sols.push_back(set);

        }
        return sols;
    }
};

int main(){
	int a[] = {1,2,3};
	vector<int> vec(a , a+3);
	Solution s;
	vector<vector<int> > sol= s.subsets(vec);
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}