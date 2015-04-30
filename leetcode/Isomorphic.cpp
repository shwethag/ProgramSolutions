#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/
class Solution {

public:
    bool isIsomorphic(string s, string t) {
    	map<char,char> char_map;
    	map<char,char> rev_char_map;
    	string::iterator s_iter = s.begin(),t_iter = t.begin();
    	while(s_iter!=s.end() && t_iter!=t.end()){
    		if(char_map[*s_iter]!=0){
    			if(*t_iter != char_map[*s_iter]){
    				return false;
    			}
    		}else{
    			if(rev_char_map[*t_iter]!=0){
    				return false;
    			}
    			char_map[*s_iter] = *t_iter;
    			rev_char_map[*t_iter] = *s_iter;
    		}
    		s_iter++;
    		t_iter++;
    	}
    	return true;
    }
};
int main(){
	string s1("egg"),t1("add");
	string s2("foo"),t2("bar");
	string s3("paper"),t3("title");
	Solution sol;
	bool iso = sol.isIsomorphic(s1,t1);
	if(iso){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}

	iso = sol.isIsomorphic(s2,t2);
	if(iso){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}

	iso = sol.isIsomorphic(s3,t3);
	if(iso){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}

}