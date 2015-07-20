#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    	string win;
    	if(t.length() == 0 || s.length() == 0 || s.length() < t.length())
    		return win;
        map<char,int> chmap;
        map<char,int> tmap;
        int len = -1,minlen = 0,tlen = t.length(),slen = s.length(),cnt=0;
        int st = 0,end;
        for(int i=0;i<tlen;i++)
        	tmap[t[i]]++;

        for(int i=0;i<slen;i++){
        	if(tmap[s[i]]){
        		chmap[s[i]]++;
        		if(chmap[s[i]] <= tmap[s[i]]){
        			cnt++;
        		}
        	}
        	if(cnt == tlen){
        		while(!tmap[s[st]] || chmap[s[st]] > tmap[s[st]]){
        			
        			if(chmap[s[st]] > tmap[s[st]])	chmap[s[st]]--;
        			st++;
        		}
        		end = i;
        		len = end - st + 1;
        		if(!minlen || len < minlen){
        			minlen = len;
        			cnt--;
        			chmap[s[st]]--;

        			win = s.substr(st,len);
        			st++;
        		}
        	}
        }

        return win;
    }
};

int main(){
	Solution s;
	string win = s.minWindow("BCECODEBANC","ABC");
	cout<<win<<endl;
	return 0;
}