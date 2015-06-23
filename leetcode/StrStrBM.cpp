#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haylen = haystack.length();
        int nlen = needle.length();
        map<char,int> shiftmap;

        if(haylen == 0 && nlen == 0)
        	return 0;
        if(nlen == 0 || haylen < nlen)
            return 0;

        for(int i=nlen-1;i>=0;i--){
        	if(!shiftmap[needle[i]])
        		shiftmap[needle[i]] = nlen-i-1;
        }

        for(int i=0;i<haylen;i++){
        	if(!shiftmap[haystack[i]])
        		shiftmap[haystack[i]] = nlen;
        }

        int i=nlen-1,j=nlen-1;
        while(i<haylen){
        	if(haystack[i]!=needle[j]){
        		i+=shiftmap[haystack[i]];

        		j=nlen-1;
        		continue;
        	}
        	while(haystack[i] == needle[j] && i>=0 && j>=0){
        		i--;
        		j--;
        	}

        	if(j >= 0){
        		i+=shiftmap[haystack[i]];
        		j=nlen-1;
        	}else{
        		return i+1;
        	}

        }


        return -1;
    }
};

int main(){
	Solution s;
	cout<<s.strStr("mississippi","issip")<<endl;
	return 0;
}