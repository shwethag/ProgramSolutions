#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	void combineUtil(vector<vector<int> > &sol,vector<int> cur,int m,int n,int k){
		if(cur.size() == k){
			sol.push_back(cur);
			cur.clear();
			return;
		}

		
		for(int i=m;i<=n;i++){
			cur.push_back(i);
			combineUtil(sol,cur,i+1,n,k);
			cur.pop_back();
		}
		


	}

    vector<vector<int> > combine(int n, int k) {

        set<vector<int> > sol;
        vector<vector<int> > ret;
        if(k == 0 || k > n)
        	return ret;

        vector<int> cur;
        combineUtil(ret,cur,1,n,k);
        
       

        return ret;
    }
};

int main(){
	Solution s;

	vector<vector<int> > sol = s.combine(4,3);

	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}