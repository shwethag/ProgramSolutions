#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cns = "";
        string prev = "1";
        int j,len,count;
        for(int i=1;i<n;i++){
        	j = 0;
        	len = prev.length();
        	while(j<len){
        		count = 1;
        		while(j+1 < len && prev[j] == prev[j+1]){
        			count++;
        			j++;
        		}
        		cns += (char)(count+'0');
        		cns += prev[j];
        		j++;

        	}

        	prev = cns;
        	cns.clear();
        }
        return prev;
    }
};

int main(){

	Solution s;
	for(int i=1;i<=10;i++){
		cout<<s.countAndSay(i)<<endl;
	}

	return 0;
}