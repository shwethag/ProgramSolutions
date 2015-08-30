#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int findlis(vector<int> &A){
		int n = A.size();
		if(!n ) return 0;
		int dp[n];
		int lis = 0;
		for(int i=0;i<n;i++)
			dp[i] = 1;
		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if(A[j] < A[i]){
					dp[i] = max(dp[i],dp[j]+1);
					if(dp[i] > lis)
						lis = dp[i];
				}
			}
		}
		return lis;
	}
};

int main(){
	int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> A(a,a+l);
	Solution s;
	cout<<s.findlis(A)<<endl;
	return 0;
}
