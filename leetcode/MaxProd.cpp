#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& A) {
        int len = A.size();
        if(!len)
            return 0;
        int maxprod=A[0],minprod=A[0], maxres = A[0],premax = A[0],premin = A[0],t;
       for(int i=1;i<len;i++){
        	maxprod = max(premax*A[i],max(premin*A[i],A[i]));
        	minprod = min(premax*A[i],min(premin*A[i],A[i]));
        	if(maxprod > maxres)
        		maxres = maxprod;
        	premax = maxprod;
        	premin = minprod;
        }
        return maxres;
    }
};

int main(){
	/*
	1, 0, 0, 0, 0, 0, -2, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, -2, 3, 0, 0, 0, 0, 0, 0, -2, -3, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, -2, 0, 0, 0, 2, -3, 0, 0, 0, 0 
	*/
	int a[] = {0, -2, -3, -3, 0, 0, 0};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> A(a,a+l);
	Solution s;
	int prod = s.maxProduct(A);
	cout<<prod<<endl;
	return 0;
}
