#include <iostream>
#include <stdint.h>
#include <math.h>

using namespace std;

/*Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int count = 0;
    	uint32_t t= 1;

        for(int i=0;i<32;i++){
        	if(n & (1<<i)){
        		count++;
        	}
        	t = t*2;
        	
        }
        return count;
    }
};

int main(){
	Solution s;
	uint32_t n=15;
	cout<<s.hammingWeight(n)<<endl;
	return 0;
}