#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	bool x;
    	uint32_t ret=0;
        for(int i=0;i<32;i++){
        	ret = ret<<1;
        	x = n & (1<<i);
        	ret |= x;

        }
        return ret;
    }
};

int main(){
	Solution s;
	cout<<s.reverseBits(3)<<endl;
	return 0;
}