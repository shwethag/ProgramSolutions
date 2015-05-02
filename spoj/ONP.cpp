#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

/*
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). 
Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). 
Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c). 

Input:
t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]

Text grouped in [ ] does not appear in the input file. 

Output:

The expressions in RPN form, one per line.

Example:
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

*/

string transform(string expression){
	string trans  = expression;
	stack<string> operand_stack,operator_stack;
	int len = expression.length();
	for(int i=0;i<len;i++){
		if(expression[i] == '(' || (expression[i] >= 'a' && expression[i] <= 'z')){
			string chr(1,expression[i]);
			operand_stack.push(chr);
		}
		else if(expression[i] == ')'){
			string right = operand_stack.top();
			operand_stack.pop();
			string left = operand_stack.top();
			operand_stack.pop();
			string oper = operator_stack.top();
			operator_stack.pop();
			if(operand_stack.top()=="(")
				operand_stack.pop();
			operand_stack.push(left+right+oper);
		}else{
			string chr(1,expression[i]);
			operator_stack.push(chr);
		}
	}

	return operand_stack.top();
}

int main(){
	int testcases;
	string expression;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>expression;
		string rpn = transform(expression);
		cout<<rpn<<endl;
	}
	return 0;
}