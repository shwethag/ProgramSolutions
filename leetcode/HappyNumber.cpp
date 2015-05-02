#include <iostream>
#include <map>

using namespace std;

/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in
a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

*/

class Solution {
	map<int,bool> num_map;
public:
	int getDigitSum(int n){
		int total = 0;
        while(n!=0){
        	int digit = n%10;
        	total += (digit*digit);
        	n = n/10;
        }
        return total;
	}

    bool isHappy(int n) {
    	num_map[n]='t';
    	int sum;
    	while((sum=getDigitSum(n))!=1 && !num_map[sum]){
    		num_map[sum] = true;
    		n = sum;
    	}
    	if(sum == 1)
    		return true;
    	return false;
    }
};

int main(){
	Solution s;
	bool isHappy = s.isHappy(19);
	if(isHappy)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}