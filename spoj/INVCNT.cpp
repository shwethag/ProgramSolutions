#include <iostream>
#include <climits>
#define LEN 200010

using namespace std;
int arr[LEN];
long long int invCnt = 0;

void merge(int l,int mid,int r){
	int left[mid-l+1],right[r-mid+1];
	int i,j,k,llen,rlen;
	for(k=0,i=l;i<=mid;i++){
		left[k++] = arr[i];
	}
	left[k] = INT_MIN;
	llen = k;
	for(k=0,i=mid+1;i<=r;i++){
		right[k++] = arr[i];
	}
	right[k] = INT_MIN;
	rlen = k;

	i=l;
	k=0;
	j=0;

	for(i=l;i<=r;i++){
		if(left[k] < right[j]){
			arr[i] = right[j++];

		}else{
			arr[i] = left[k++];
			invCnt += rlen-j;
		}
	}
}

void computeInvCount(int left, int right){
	if(left < right){
		int mid = left + (right-left)/2;
		computeInvCount(left,mid);
		computeInvCount(mid+1,right);
		merge(left,mid,right);
	}
}



int main(){
	std::ios_base::sync_with_stdio(false);
	
	int t,n,j,tmp;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		invCnt = 0;
		computeInvCount(0,n-1);
		
		cout<<invCnt<<endl;
	}

	return 0;
}