#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int distinctUtil(string s,string t,int i,int j,vector<vector<int> > &dp){
		//int l1 = s.size(),l2 = t.size();
		if(j < 0)
			return 1;
		if(i < 0)
			return 0;
		if(dp[i][j] != 0)
			return dp[i][j];
		if(s[i] == t[j])
			dp[i][j] =  distinctUtil(s,t,i-1,j-1,dp) + distinctUtil(s,t,i-1,j,dp);
		else 
			dp[i][j] =  distinctUtil(s,t,i-1,j,dp);

		return dp[i][j];
	}

    int numDistinct(string s, string t) {
    	vector<vector<int> > dp;
    	int l1 = s.size();
    	int l2 = t.size();
    	dp.resize(l1);

    	for(int i=0;i<l1;i++){
    		dp[i].resize(l2,0);
    	}
        return distinctUtil(s,t,s.size()-1,t.size()-1,dp);
    }
};

int main(){
	string s = "ds", t = "";

	Solution sol;
	int seq = sol.numDistinct(s,t);
	cout<<seq<<endl;

	return 0;
}