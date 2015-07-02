#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s){
		if(s == "")
			return false;
		int len = s.length();
		int i=0,j=len-1;
		while(i<j){
			if(s[i] != s[j])
				return false;
			i++;
			j--;
		}

		return true;

	}

	void partitionUtil(vector<vector<string> > &pals, vector<string> part, string cur, string s){
		if(s.length() == 0){
			if(part.size()!=0){
				pals.push_back(part);
			}
		}else{
			char c = s[0];
			cur +=c;
			s = s.substr(1);
			//cout<<cur<<endl;
			if(isPalindrome(cur))
			{	
				//cout<<cur<<endl;
				part.push_back(cur);
				string tmp1 = cur;
				//cout<<"cstring: "<<cur<<" " <<s<<endl;
				cur = "";
				partitionUtil(pals,part,cur,s);
				part.pop_back();
				cur = tmp1;
				if(s.length()!=0)
					partitionUtil(pals,part,cur,s);
			}else{
				//cout<<"cestr: "<<cur<< " "<<s<<endl;
				if(s.length() == 0)
					part.clear();
				partitionUtil(pals,part,cur,s);
			}


		}
	}

    vector<vector<string> > partition(string s) {
        vector<vector<string> > pals;
        vector<string> part;
        string cur = "";
        partitionUtil(pals,part,cur,s);
        return pals;
    }
};

int main(){
	string str = "aabba";
	Solution s;
	vector<vector<string> > pals =  s.partition(str);

	for(int i=0;i<pals.size();i++){
		for(int j=0;j<pals[i].size();j++){
			cout<<pals[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}