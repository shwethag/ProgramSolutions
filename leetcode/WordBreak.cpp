#include <iostream>

using namespace std;


class Solution {
public:
    bool breakword(string s,int st,vector<bool> &dp,unordered_set<string>& wordDict){
        int n = s.size();
        if(n == 0)
            return true;
        for(int i= 1;i<=n;i++){
            if(dp[st+i] || wordDict.find(s.substr(0,i))!=wordDict.end()){
                dp[st+i] = true;
            }
            if(dp[st+i] && breakword(s.substr(i),st+i,dp,wordDict))
                return true;
        }
        return false;
    }
    
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n,false);
        return breakword(s,0,dp,wordDict);
    }
};

int main(){
	
	return 0;
}