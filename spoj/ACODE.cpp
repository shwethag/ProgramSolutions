#include <iostream>
#include <cstring>

using namespace std;

int dp[5010];

int getPossibleEncode(char *digits,int len){
	if(len == 0 ){
		return 0;
	}else if(len == 1){
		if(digits[len-1]=='0')
			return 0;
		else
			return 1;
	}
	int val2 = digits[len-1] - '0';
	int val1 = digits[len-2] - '0';
	if(dp[len] != 0)
		return dp[len];
	
	if(len ==  2 ){
		if(val1 == 0 || (val1 > 2 && val2 == 0)){
			dp[len] = 0;
		}
		else if((val1 == 1 && val2 !=0)  || (val1 == 2 && val2 <= 6 && val2 != 0)){
			dp[len] = 2;
		}else {
			dp[len] = 1;
		}
	}
	else if(val1 == 0){
		dp[len] = getPossibleEncode(digits,len-1);
	}
	else if((val1 == 1 && val2 !=0)  || (val1 == 2 && val2 <= 6 && val2 != 0)){
		dp[len] = getPossibleEncode(digits,len-1) + getPossibleEncode(digits,len-2);
	}else if(val2 == 0){
		dp[len] = getPossibleEncode(digits, len-2);
	}else{
		dp[len] = getPossibleEncode(digits,len-1);
	}

	return dp[len];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	
	char digits[5010];
	int len;
	while(true){
		cin>>digits;
		if((len = strlen(digits)) == 1 && digits[0] == '0')
			break;

		for(int i=0;i<=len;i++){
			dp[i] = 0;
		}

		cout<<getPossibleEncode(digits,len)<<endl;
	}

	return 0;
}