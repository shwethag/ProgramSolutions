#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int getmins1(vector<int> &A,vector<int> &B){
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	int l = A.size();
	map<int,int> available;
	for(int i=0;i<l;i++){
		available[A[i]]++;
	}	

	int m = B.size();
	vector<int> remaining;
	for(int i=0;i<m;i++){
		if(available[B[i]] > 0){
			available[B[i]]--;
		}else{
			remaining.push_back(B[i]);
		}
	}

	int n = remaining.size();
	int j = 0;
	int maxval = 0;
	for(int i=0;i<l;i++){
		if(!available[A[i]])
			continue;
		if(j >= n)
			break;
		if(abs(remaining[j] - A[i]) > maxval)
			maxval = abs(remaining[j] - A[i]);

		j++;

	}
	return maxval;

}

int getmins(vector<int> &A,vector<int> &B){
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int l = A.size();
	int maxval = 0,diff;
	for(int i=0;i<l;i++){
		diff = abs(A[i]-B[i]);
		if(diff > maxval)
			maxval = diff;
	}
	return maxval;
}

int main(){
	int a[] = {4,-4,2};
	int b[] = {4,0,5};

	vector<int> A(a,a+3);
	vector<int> B(b,b+3);

	cout<<getmins(A,B)<<endl;

	return 0;
}