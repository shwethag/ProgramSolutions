#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 
*/
struct data{
	int index,height;
};
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int curMax = 0,curArea,len = height.size(),left;
        data d,cur;
        stack<data> stck;
        for(int i=0;i<=len; i++){
        	while(!stck.empty() && (i == len || stck.top().height > height[i])){
        		cur = stck.top();
        		stck.pop();
        		if(stck.size() > 0)
        			left = stck.top().index;
        		else
        			left = -1;
        		curArea = (i-left-1) * cur.height;
        		if(curArea > curMax)
        			curMax = curArea;
        	}
        	if(i<len){
	      		d.index = i;
	      		d.height = height[i];
	      		stck.push(d);
	      	}
        }

        return curMax;
    }
};

int main(){
	int a[] = {2,1,2};
	vector<int> height(a,a+3);
	Solution s;

	cout<<s.largestRectangleArea(height)<<endl;
	return 0;
}