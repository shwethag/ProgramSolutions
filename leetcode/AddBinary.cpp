#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int l1 = a.length(),l2 = b.length();
        int l = max(l1,l2);
        bool carry = false;
        int d1,d2,sum;
        int i,j;
        for(i=l1-1,j=l2-1;(i>=0 || j>=0);i--,j--){
        	d1 = (i>=0)?a[i]-'0':0;
        	d2 = (j>=0)?b[j]-'0':0;
        	sum = d1 + d2 + carry;
        	switch(sum){
        		case 0:
        		case 1:
        			res += (char)(sum+'0');
        			carry = false;
        			break;
        		case 2:
        			res += '0';
        			carry = true;
        			break;
        		case 3: 
        			res += '1';
        			carry = true;

        	}


        }

        if(carry)
        	res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
	Solution s;
	cout<<s.addBinary("111","101")<<endl;
	return 0;
}