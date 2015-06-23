#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public: 
    bool rotatedSearch(vector<int> values, int start, int end, 
                              int x){
        if(values[start] == x){
            return true;
        } else if(values[end] == x){
            return true;
        } else if(start == end){
            return false;
        } else if(end - start == 1) {
            return false;
        } 
        int middle = start + (end-start) / 2;

        if(values[start] == values[end]){
            return (rotatedSearch(values,start,middle,x) | rotatedSearch(values,middle,end,x));

        }if(values[start] <= values[middle]){
            if(x <= values[middle] && x >= values[start]){
                return rotatedSearch(values, start, middle, x);
            } else {
                return rotatedSearch(values, middle, end, x);
            }
        } else if(values[middle] <= values[end]){
            if(x >= values[middle] && x <= values[end] ){
                return rotatedSearch(values, middle, end, x);
            } else {
                return rotatedSearch(values, start, middle, x);
            }
        } else {
            return false;
        }
    }

    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        return rotatedSearch(nums,0,len-1,target);   
    }

};

int main(){
    int a[] = {1,1,1};
    int len = sizeof(a)/sizeof(a[0]);
    cout<<len<<endl;
    vector<int> nums(a,a+len);
    Solution s;
    /*for(int i=0;i<=8;i++)
        cout<<i<<" " <<s.search(nums,i)<<endl;*/
    cout<<s.search(nums,0)<<endl;
    return 0;
}