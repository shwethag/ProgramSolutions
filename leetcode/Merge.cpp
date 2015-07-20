#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0,j=0,k=0;
        int a,b;
        int sum = m+n;
        vector<int> mer;
        while(i<sum){
        	a = (i<m)?nums1[i]:INT_MAX;
        	b = (j<n)?nums2[j]:INT_MAX;
            if(a<b){
            	mer.push_back(nums1[i]);
                i++;
            }else{
            	int num = nums2[j];
                nums1.insert(nums1.begin()+i,num);
                j++;
                i++;
                m++;
            }
        }
        nums1.erase(nums1.begin()+sum,nums1.end());
    }
};

int main(){
	int a[] = {1,1,3,3,4,6,7};
	int b[] = {2,2,3,3,4,4,5,9};
	//int b[] = {1};
	int l1 = sizeof(a)/sizeof(a[0]);
	int l2 = sizeof(b)/sizeof(b[0]);

	vector<int> nums1(a,a+l1);
	vector<int> nums2(b,b+l2);

	Solution s;

	s.merge(nums1,l1,nums2,l2);

	for(int i=0;i<nums1.size();i++){
		cout<<nums1[i]<<" ";
	}
	cout<<endl;

	return 0;
}