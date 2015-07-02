#include <iostream>
#include <string>
#include <vector>

using namespace std;

string letters[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


class Solution {
public:

	void generateString(string digits,string &temp,vector<string> &comb){
		if(digits.length() == 0)
		{	
			comb.push_back(temp);
			return;
		}
		int pos = digits[0]-'0';
		for(int i=0;i<letters[pos].length();i++){
			temp.push_back(letters[pos][i]);
			generateString(digits.substr(1),temp,comb);
			temp.erase(temp.end()-1);
		}
	}

    vector<string> letterCombinations(string digits) {
        vector<string> comb;
        if(digits.length() == 0)
        	return comb;
        string temp;
        generateString(digits,temp,comb);
        return comb;
    }
};

int main(){
	Solution s;
	vector<string> comb = s.letterCombinations("");

	for(int i=0;i<comb.size();i++){
		cout<<comb[i]<<" ";
	}
	cout<<endl;
	return 0;
}