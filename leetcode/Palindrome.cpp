#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution{
public:

	bool isPalindrome(string s){
		int len = s.length();
		if(len == 0 || len == 1)
			return true;
		int i=0,j=len-1;
		while(!isalpha(s[i]))
				i++;
		while(!isalpha(s[j]))
				j--;
		while(i<=j){

			if(tolower(s[i])!=tolower(s[j]))
				return false;
			i++;
			j--;
			while(!isalpha(s[i]))
				i++;
			while(!isalpha(s[j]))
				j--;
		}
		return true;
	}
};

int main(){
	string str = "race a car";
	Solution s;
	cout<<s.isPalindrome(str)<<endl;

	return 0;
}