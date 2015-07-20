#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	void grayUtil(vector<int> &sol,int c,int max){
		if(max == 0)
			return;
		int x = (c >> 1) ^ c;
		sol.push_back(x);
		
		grayUtil(sol,c+1,max-1);
	}

    vector<int> grayCode(int n) {
        vector<int> sol;
        if(n == 0){
        	sol.push_back(0);
        	return sol;
        }
        grayUtil(sol,0,pow(2,n));
       	return sol;
    }
};

int main(){

	Solution s;
	vector<int> gray = s.grayCode(3);
	for(int i=0;i<gray.size();i++){
		cout<<gray[i]<<endl;
	}

	return 0;
}
