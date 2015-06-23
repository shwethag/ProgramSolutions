#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> getPrefixTable(string needle){
        int len = needle.length();
        vector<int> pTable;
        pTable.resize(len,0);
        int i=1,j=0;
        pTable[0]=0;
        while(i<len){
            if(needle[i]==needle[j]){
                pTable[i] = j+1;
                i++;
                j++;
            }else if(j>0){
                j = pTable[j-1];
            }else{
                pTable[i] = 0;
                i++;
            }
        }

        return pTable;
    }

    int strStr(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        if(hlen == 0 && nlen == 0)
            return 0;
        if(nlen == 0)
            return 0;

        vector<int> pTable = getPrefixTable(needle);
        int i=0,j=0;
        while(i<hlen){
            if(haystack[i] == needle[j]){
                if(j == nlen -1 ){
                    return i-j;
                }else{
                    i++;
                    j++;
                }
            }else if(j>0){
                j = pTable[j-1];
            }else{
                i++;
            }
        }
        return -1;
    }
};

int main(){
	Solution s;
	cout<<s.strStr("","")<<endl;
	return 0;
}