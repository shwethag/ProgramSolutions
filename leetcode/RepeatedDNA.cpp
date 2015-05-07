#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> seq;
        int k = s.size()/10;
        for(int i=0;i<k;i++){
        	map[s.substr(10*i,10)]++;
        }
        vector<string> repeated;
        for(map<string,int>::iterator it = seq.begin();
    }
};


int main(){
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution s;
	vector<string> repeated = s.findRepeatedDnaSequences(s);
	int len = repeated.size();
	for(int i=0;i<len;i++){
		cout<<repeated[i]<<endl;
	}
	
	return 0;
}