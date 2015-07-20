#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<string> construct(int n){
		vector<string> qarr;
		for(int i=0;i<n;i++){
			string s(n,'.');
			qarr.push_back(s);
		}
		return qarr;
	}

	bool isPossible(vector<string> qarr,int r,int c){
		int n = qarr.size();
		for(int i=0;i<r;i++){
			if(qarr[i][c] == 'Q')
				return false;
		}
		for(int i=0;i<c;i++){
			if(qarr[r][i] == 'Q')
				return false;
		}
		int i = r-1,j = c-1;
		for(;i>=0 && j>=0;i--,j--){
			if(qarr[i][j] == 'Q')
				return false;
		}
		i = r-1; j = c + 1;
		for(;i>=0 && j < n;i--,j++){
			if(qarr[i][j] == 'Q')
				return false;
		}
		return true;
	}

	

	void nQueensUtil(vector<vector<string> > &sol,vector<string> qarr,int r,int c,int n){
		if(r >= n && c >= n)
			return;
		if(c >= n){
			return;//nQueensUtil(sol,qarr,r+1,0,n);

		}else if(r >= n){
			sol.push_back(qarr);
			return;
		}else{
			if(isPossible(qarr, r,c)){
				qarr[r][c] = 'Q';
				nQueensUtil(sol,qarr,r+1,0,n);
			}
			qarr[r][c] = '.';
			nQueensUtil(sol,qarr,r,c+1,n);
		}

	}

    vector<vector<string> > solveNQueens(int n) {
    	vector<string> qarr = construct(n);
    	vector<vector<string> > sol;

    	nQueensUtil(sol,qarr,0,0,n);
    	return sol;
    }
};

int main(){
	Solution s;
	vector<vector<string> > sol = s.solveNQueens(3);
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++){
			cout<<sol[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}