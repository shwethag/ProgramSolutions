#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

/*
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is: 

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len = S.size();
        int maxsubset = pow(2,len);
        set<vector<int> > sol_set;
        for(int i=0;i<maxsubset;i++){
        	vector<int> set;
        	for(int j=0;j<len;j++){
        		if(i & (1<<j)){
        			set.push_back(S[j]);
        		}
        	}
        	sort(set.begin(),set.end());
        	sol_set.insert(set);

        }
        vector<vector<int> > sol_vector;
        for(set<vector<int> >::iterator it = sol_set.begin();it!=sol_set.end();it++){
        	sol_vector.push_back(*it);
        }
        return sol_vector;
    }
};

int main(){
	int a[] = {1,2,2};
	vector<int> vec(a , a+3);
	Solution s;
	vector<vector<int> > sol= s.subsetsWithDup(vec);
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}