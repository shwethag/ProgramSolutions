#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void parentheisUtil(vector<string> &par, string cur,int open,int close){
		if(open == 0 && close == 0){
			par.push_back(cur);
			return;
		}
		if(open > close)
			return;
		if(open > 0){
			parentheisUtil(par,cur+"(",open-1,close);
		}
		if(close > 0){
			parentheisUtil(par,cur+")",open,close-1);
		}
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> par;
    	if(n == 0)
    		return par;
    	string cur;
        parentheisUtil(par,cur,n,n);
        return par;
    }
};

int main(){
	vector<string> par;
	Solution s;

	par = s.generateParenthesis(5);

	for(int i=0;i<par.size();i++){
		cout<<par[i]<<endl;
	}

	return 0;
}