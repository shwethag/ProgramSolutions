#include <iostream>

using namespace std;

class Solution {

public:
    double myPow(double x, long int n) {
    	cout<<n<<endl;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n < 0){
        	return 1.0/myPow(x,-n);
        }
        if(n%2 == 0){
            double y = myPow(x,n/2);
            cout<<y<<endl;
            return y*y;
        }
        else
            return x * myPow(x,n-1);
    }
};

int main(){
	Solution s;
	long int n = -21474836478;
	cout<<n<<" "<<-n<<endl;
	cout<<s.myPow(1.00000, -2147483648)<<endl;

	return 0;
}