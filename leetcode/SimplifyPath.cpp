#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<char> stck;
        int len = path.length();
        for(int i=0;i<len;i++){
        	if(path[i]=='/'){
        		if(!stck.empty() && stck.top() == '/'){
        			continue;
        		}
        		stck.push(path[i]);
        	}else if(path[i] == '.'){
        		if(i+1 != len && path[i+1] == '.' ){
        			if(i+2 != len && path[i+2] != '/'){
        				while(i< len && path[i] == '.')
        				{
        					stck.push(path[i]);
        					i++;
        				}
        				i--;
        			}else{
	        			i++;
	        			while(!stck.empty() && stck.top()!='/')
	        				stck.pop();
	        			stck.pop();
	        			while(!stck.empty() && stck.top()!='/')
	        				stck.pop();
	        		}
        		}else if(i+1 !=len && path[i+1] == '/'){
        			i++;
        			while(!stck.empty() && stck.top()!='/')
        				stck.pop();
        		}else if(i+1 != len && path[i+1] !='/'){
        			stck.push(path[i]);
        		}
        	}else{
        		stck.push(path[i]);
        	}
        }
        string spath = "";
        if(!stck.empty() && stck.top()=='/')
        	stck.pop();
        while(!stck.empty()){
        	spath = stck.top() + spath;
        	stck.pop();
        }
        if(spath == "")
        	spath = "/";
        return spath;
    }
};

int main(){

	Solution s;
	cout<<s.simplifyPath("/home/")<<endl;
	cout<<s.simplifyPath("/a/./b/../../c/")<<endl;
	cout<<s.simplifyPath("/../")<<endl;
	cout<<s.simplifyPath("/home//foo/")<<endl;
	cout<<s.simplifyPath("/.....hidden")<<endl;
	cout<<s.simplifyPath("/..hidden")<<endl;
	cout<<s.simplifyPath("/.hidden")<<endl;
	cout<<s.simplifyPath("/.")<<endl;

	return 0;
}