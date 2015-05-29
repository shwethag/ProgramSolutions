#include <iostream>
#include <vector>

using namespace std;

/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


*/


class Solution {
public:
    int trap(vector<int>& height) {
    	int len = height.size();
        int leftMax[len],rightMax[len],curLeftMax,curRightMax;

        curLeftMax = 0;
        for(int i=0;i<len;i++){
        	leftMax[i] = curLeftMax;
        	if(height[i] > curLeftMax)
        		curLeftMax = height[i];
        }

        curRightMax = 0;
        for(int i=len-1;i>=0;i--){
        	rightMax[i] = curRightMax;
        	if(height[i] > curRightMax)
        		curRightMax = height[i];
        }


        int trapwater = 0;

        for(int i=0;i<len;i++){
        	trapwater += max(0,min(rightMax[i],leftMax[i]) - height[i]);
        }

        return trapwater;
    }
};

int main(){
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height(a,a+12);

	Solution s;
	cout<<s.trap(height)<<endl;
	return 0;
}