#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	string pre_process(string s){
		string p;
		int len = s.length();
		for(int i=0;i<len;i++){
			p.push_back('#');
			p.push_back(s[i]);

		}
		p.push_back('#');
		return p;
	}
    string longestPalindrome(string s) {
    	int len = s.length();
    	if(len == 0 || len == 1)
    		return s;

        string p = pre_process(s);
        len = p.length();
        int t[len];
        t[0] = 0;
        t[len-1] = 0;
        int center = 0,radius = 0,i_mirror;
        for(int i=1;i<len-1;i++){
        	i_mirror = 2*center - i;
        	t[i] = (radius > i)?min(radius-i,t[i_mirror]):0;
        	while((i+t[i]+1) < len && (i-1-t[i]) >=0 && p[i+t[i]+1] == p[i-1-t[i]]){
        		t[i]++;
        	}

        	if(i+t[i] > radius){
        		radius = i + t[i];
        		center = i;
        	}
        }

        for(int i=0;i<len;i++){
        	cout<<t[i]<<" ";
        }
        cout<<endl;

        int maxlen = 0;
        center = 0;
        for(int i=1;i<len-1;i++){
        	if(t[i] > maxlen){
        		maxlen = t[i];
        		center = i;
        	}
        }
        int st = ceil((center - maxlen - 1)/2.0);
        return s.substr(st,maxlen);
    }
};

int main(){
	string str = "ananabanana";
	Solution s;
	cout<<s.longestPalindrome(str)<<endl;
	return 0;
}