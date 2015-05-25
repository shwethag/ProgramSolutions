#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/


class Solution {
public:
	bool isOperator(string op){
		if(op == "+" || op == "-" || op == "*" || op == "/")
			return true;
		return false;
	}

	int getInteger(string str){
		int len = str.length();
		int num = 0,i;
		if(str[0] == '-'){
			i = 1;
		}else{
			i = 0;
		}
		for(;i<len;i++){
			num += (str[i]-'0');
			num = num*10;
		}
		if(str[0] == '-')
			num = -num;
		return num/10;
	}

    int evalRPN(vector<string>& tokens) {
    	stack<int> stck;
    	int num1,num2;
    	string oper1,oper2,op;
    	int len = tokens.size();
    	for(int i=0;i<len;i++){
    		if(isOperator(tokens[i])){
    			num2 = stck.top();
    			
    			stck.pop();
    			num1 = stck.top();

    			
    			stck.pop();
    			op = tokens[i];
    			if(op == "+"){
    				stck.push(num1+num2);
    			}else if(op == "-"){
    				stck.push(num1-num2);
    			}else if(op == "*"){
    				stck.push(num1*num2);
    			}else if(op == "/"){
    				stck.push(num1/num2);
    			}
    		}else{
    			stck.push(getInteger(tokens[i]));
    		}
    	}

    	return stck.top();
        
    }
};

int main(){
	Solution s;
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");

	cout<<s.evalRPN(tokens)<<endl;

	tokens.clear();

	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	cout<<s.evalRPN(tokens)<<endl;

	tokens.clear();

	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");
	cout<<s.evalRPN(tokens)<<endl;

	return 0;
}