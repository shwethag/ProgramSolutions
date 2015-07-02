#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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


/*void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }*/

	
	void generate(vector<vector<int> > &perms, vector<int> A,int i,int len){
		if(i == len){
			perms.push_back(A);
		}else{
			for(int j=i;j<=len;j++){
				if(j!=i && A[i] == A[j]) continue;
				swap(A[i],A[j]);
				generate(perms,A,i+1,len);
			}
		}
	}

    vector<vector<int> > permuteUnique(vector<int> &A) {
        vector<vector<int> > pvec;
        sort(A.begin(),A.end());
        generate(pvec,A,0,A.size()-1);
       
        return pvec;

    }
};

int main(){
	int a[] = {3,3,0,0,2,3,2};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+l);
	Solution s;
	vector<vector<int> > perms = s.permuteUnique(v);
	for(int i=0;i<perms.size();i++){
		for(int j=0;j<perms[i].size();j++){
			cout<<perms[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

