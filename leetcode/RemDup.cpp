#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       vector<int>::iterator it = nums.begin(),nxt;
       int len = nums.size(),val;
       int i=0;
       while(it!=nums.end()){
       		val = *it;
       		it++;
       		i++;
       		nxt = it;
       		while(nxt!=nums.end() && *nxt == val){
       			nxt++;
       		}
       		if(it != nxt)
       			nums.erase(it,nxt);
       		it = nums.begin()+i;

       }
       return nums.size();
    }
};

int main(){

	int a[] = {1,1,1,1,3};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+0);
	Solution s;
	cout<<s.removeDuplicates(v)<<endl;
	return 0;
}