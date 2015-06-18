#include <iostream>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

class Solution{
public:
	int atoi(string s){
		   long long int num = 0;
		int len = s.length();
		int i=0;
		while(i<len && s[i]==' ')
		    i++;
		bool neg = false;
		if(s[i] == '-')
		{
		    neg = true;
		    i++;
		}else if(s[i] == '+')
			i++;
		
		while(i<len && isdigit(s[i])){
			num = num*10;
			if(num!=int(num))
				break;
			num += s[i]-'0';
			i++;
		}
		if(neg)
		    num = -num;
		if(num != (int)num)
		{
		    if(neg)
		        return INT_MIN;
		    else
		        return INT_MAX;
		}
		return (int)num;
	}
};

int main(){
	int num = INT_MAX;
	cout<<num<<endl;
	string str = "18446744073709551617";
	Solution s;
	cout<<s.atoi(str)<<endl;

	return 0;
}