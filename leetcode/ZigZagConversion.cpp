#include <iostream>
#include <string>

using namespace std;

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
    string convert(string s, int numRows) {

    	if(s.length() == 0 || numRows <=1 )
    		return s;
        string zigzag = "";
        int len = s.length();
        int i = 0,row = 1;
        int gapfirst = numRows + (numRows-2);
        while(i<len){
        	zigzag.push_back(s[i]);
        	i+=gapfirst;
        }
        row++;
        int gap1 = gapfirst -2,gap2 = 2;
        bool isGap1 = true;
        while(row < numRows){
        	i=row-1;
        	while(i<len){
        		zigzag.push_back(s[i]);
        		if(isGap1){
        			i+=gap1;
        		}else{
        			i+=gap2;
        		}
        		isGap1 = !isGap1;
        	}
        	gap1 = gap1-2;
        	gap2 = gap2+2;
        	isGap1 = true;
        	row++;
        }

        i = numRows-1;
        while(i<len){
        	zigzag.push_back(s[i]);
        	i+=gapfirst;
        }
        return zigzag;
    }
};

int main(){
	string str = "PAYPALISHIRING";

	Solution s;
	cout<<s.convert("ABCDE",4)<<endl;
	return 0;
}