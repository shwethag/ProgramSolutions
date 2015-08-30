#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int diff,mn,mx;
class Solution {
public:

    
    int maximumGap(vector<int>& A) {
        int len = A.size();
        if(len < 2)
            return 0;
        if(len == 2)
            return A[0] < A[1] ? A[1] - A[0] : A[0] - A[1];

        int min_val = INT_MAX,max_val = INT_MIN;
        for(int i=0;i<len;i++){
			if(A[i] < min_val) min_val = A[i];
			if(A[i] > max_val) max_val = A[i];        
        }
        cout<<"here<"<<endl;
        int buckt_cnt = min(len/2,(max_val - min_val)/2);

        vector<int> buck_min(buckt_cnt,max_val),buck_max(buckt_cnt,min_val);
        cout<<"here<"<<endl;
        int id;
        for(int i=0;i<len;i++){
        	id = i%buckt_cnt;
        	buck_min[id] = min(A[i],buck_min[id]);
        	buck_max[id] = max(A[i],buck_max[id]);
        }

        int max_gap = INT_MIN,lst_max = min_val;
        for(int i=0;i<buckt_cnt;i++){
        	cout<<buck_min[i]<<" "<<buck_max[i]<<endl;
        	max_gap = max(lst_max - buck_min[i],max_gap);
        	if(lst_max < buck_max[i])
        		lst_max = buck_max[i];
        } 
        
    }
};

int main(){
	int a[] = { 3,6,9,1};
	int l = sizeof(a)/sizeof(a[0]);

	vector<int> v(a,a+l);
	Solution s;
	int diff = s.maximumGap(v);
	cout<<diff<<endl;
	return 0;
}