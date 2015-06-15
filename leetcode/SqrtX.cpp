#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
        	return x;
        double precision = 0.00001;
        double start=0.0,end = (double)x;
        double mid=0.0,midsq;
        while((end-start)>precision){
        	mid = start+(end-start)/2;
        	midsq = mid*mid;
        	if((int)midsq == x){
        		return mid;
        	}
        	if(midsq < x)
        		start = mid;
        	else
        		end = mid;
        }
        //mid+=0.05;
        return mid;
    }
};

int main(){
	int num = 0;
	Solution s;
	for(int i=0;i<=40;i++)
		cout<<i<<" "<<s.mySqrt(i)<<endl;
	return 0;
}