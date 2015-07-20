#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

using namespace std;

class Solution {
public:
	/*
		4/2
		1/2
		2/5
		5/3 -- 2/3
	*/


    string fractionToDecimal(int n, int d) {
    	if(n == 0){
    		return "0";
    	}
    	long int A = (long int)n;
    	long int B = (long int)d;
    	//long int A=n,B = d;
        string sol = "";
        if(A < 0 ^ B < 0){
        	sol += "-";
        }
        A = abs(A);
        B = abs(B);
        //cout<<A<<" "<<B<<endl;
        map<int,int> fracmap;
        long int part;
        string seg;
        stringstream out;
        part = A/B;
        out<<part;
        sol += out.str();
        A = A % B;

        if(A == 0){

        	return sol;
        }
        sol += ".";
        while(A!=0){
        	//cout<<A<<" "<<B<<endl;
        	if(fracmap[A]){
        		sol.insert(fracmap[A],"(");
        		sol += ")";
				break;
        	}

        	fracmap[A] = sol.size();
        	stringstream out;
        	A = A * 10;
        	part = A/B;
        	out<<part;
        	seg = out.str();
        	

        	A = A % B;
        	sol += out.str();
        	
        	//cout<<part<<endl;
        }
      
        return sol;
    }
};

int main(){
	Solution s;
	string frac = s.fractionToDecimal(-2147483648, 1);
	cout<<frac<<endl;
	return 0;
}