#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchlow(vector<int>& A, int B,int low,int high){
		int mid;
		while(low<=high){
			mid = low + (high-low)/2;
			if(mid == low && A[mid] == B)
				return mid;
			else if(mid > low && A[mid] == B && A[mid-1]!=B)
				return mid;

			if(B > A[mid])
				return searchlow(A,B,mid+1,high);
			else
				return searchlow(A,B,low,mid-1);
		}
		return -1;
	}

	int searchhigh(vector<int>& A, int B,int low,int high){
		int mid;
		while(low<=high){
			mid = low + (high-low)/2;
			if(mid == high && A[mid] == B)
				return mid;
			else if(mid < high && A[mid] == B && A[mid+1]!=B)
				return mid;

			if(B >= A[mid])
				return searchhigh(A,B,mid+1,high);
			else
				return searchhigh(A,B,low,mid-1);
		}
		return -1;
	}

    vector<int> searchRange(vector<int>& A	, int B) {
        int low = 0,high = A.size()-1,mid;
        bool rlow,rhigh;
        rlow=rhigh=false;
        vector<int> range;
        range.push_back(-1);
        range.push_back(-1);
        while(low<=high){
        	mid  = low + (high-low)/2;
        	if(mid==low && B == A[mid]){
        		range[0] = mid;
        		rlow = true;
        	}
        	else if(mid>low && B==A[mid] && A[mid-1]!=B){
        		range[0] = mid;
        		rlow = true;
        	}

        	if(mid == high && B == A[mid]){
        		range[1] = mid;
        		rhigh = true;
        	}
        	else if(mid < high && B == A[mid] && B!=A[mid+1]){
        		range[1] = mid;
        		rhigh = true;
        	}

        	if(rlow && rhigh)
        		return range;

        	if(A[mid]<B){
        		low = mid+1;
        	}else if(A[mid] > B){
        		high = mid-1;
        	}else{
        		range[0] = searchlow(A,B,low,mid);
        		range[1] = searchhigh(A,B,mid,high);
        		break;
        	}



        }
        return range;
    }
};

int main(){
	int a[] = {2,2,3,3};
	int len = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+len);
	Solution s;
	vector<int> range = s.searchRange(v,3);
	cout<<range[0]<<" "<<range[1]<<endl;
	return 0;
}