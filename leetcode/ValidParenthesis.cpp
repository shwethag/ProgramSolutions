#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int len = s.length();
        for(int i=0;i<len;i++){
        	if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        		stck.push(s[i]);
        	else{
        		if(stck.empty())
        			return false;
        		char top = stck.top();
        		switch(s[i]){
        			case ')': if(top != '(') return false;
    						  stck.pop();
    						  break;
    				case ']': if(top != '[') return false;
    							stck.pop();
    							break;
    				case '}': if(top != '{') return false;
    							stck.pop();
    							break;
    				default: return false;
        		}

        	}
        }
        if(!stck.empty())
        	return false;
        return true;

    }
};

int main(){
	string str = "{}";
	Solution s;

	bool val = s.isValid(str);
	if(val)
		cout<<"Valid"<<endl;
	else
		cout<<"Invalid"<<endl;

	return 0;
}