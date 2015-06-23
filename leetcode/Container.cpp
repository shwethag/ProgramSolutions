#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0,j=len-1;
        if(len == 1)
        	return 0;
        int l,r,area,mxarea = 0;
        while(i<j){
        	l = height[i];
        	r = height[j];
        	area = min(l,r) * (j-i);
        	if(area > mxarea)
        		mxarea = area;

        	if(l < r){
        		i++;
        	}else if(l > r){
        		j--;
        	}else{
        		i++;
        		j--;
        	}
        }
        return mxarea;
    }
};

int main(){
	int a[] = {2};
	int l = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+l);

	Solution s;
	cout<<s.maxArea(v)<<endl;
	return 0;
}