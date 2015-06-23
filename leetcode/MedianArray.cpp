#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	
	int findKth(vector<int> A,vector<int> B,int k){
		int m = A.size(),n = B.size();
		if(m > n)
			return findKth(B,A,k);
		if(m == 0)
			return B[k-1];
		if(k == 1)
			return min(A[0],B[0]);
		int i = min(m,k/2),j = min(n,k/2);
		//cout<<i<<" "<<j<<endl;
		if(A[i-1] > B[j-1])
		{
			B.erase(B.begin(),B.begin()+j);
			return findKth(A,B,k-j);
		}else{
			A.erase(A.begin(),A.begin()+i);
			return findKth(A,B,k-i);
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(),l2 = nums2.size();
        int l = (l1+l2+1) >> 1;
        int r = (l1+l2+2) >> 1;
        cout<<l<<" "<<r<<endl;
        if(l == r){
            return findKth(A,B,l);
        }
        int kl = findKth(nums1,nums2,l);
        int kr = findKth(nums1,nums2,r);
        cout<<kl << " "<<kr<<endl;
        return (kl+kr)/2.0;

    }
};

int main(){
	int ar1[] = {1, 5, 7, 10, 13}, ar2[] = {11, 15,  30, 45}; // 1,2,7,10,11,13,15,23,30,45
	int l1 = sizeof(ar1)/sizeof(ar1[0]);
	int l2 = sizeof(ar2)/sizeof(ar2[0]);
	vector<int> v1(ar1,ar1+l1),v2(ar2,ar2+l2);

	Solution s;
	cout<<s.findMedianSortedArrays(v1,v2)<<endl;

	return 0;
}