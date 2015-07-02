#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

/*
1
1 2
2 1

1 2 3
1 


*/
	void swap(int &a,int &b){
		int t=a;
		a=b;
		b=t;
	}
	void generate(vector<vector<int> > &perms, vector<int> A,int i,int len){
		if(i == len){
			
			perms.push_back(A);
		}else{
			for(int j=i;j<=len;j++){
				swap(A[i],A[j]);
				generate(perms,A,i+1,len);
				swap(A[i],A[j]);
			}
		}
	}

    vector<vector<int> > permute(vector<int>& A) {
        vector<vector<int> > perms;
        vector<int> cur;
        generate(perms,A,0,A.size()-1);
        sort(perms.begin(),perms.end());
        return perms;

    }
};

int main(){
	int a[] = {1,2,3};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+l);
	Solution s;
	vector<vector<int> > perms = s.permute(v);
	for(int i=0;i<perms.size();i++){
		for(int j=0;j<perms[i].size();j++){
			cout<<perms[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

