#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

double getMinRolls(int n){
	double numerator = n;
	double rolls = 0.0;
	while(n>0){
		rolls += (numerator/n);
		n--;
	}
	return rolls;
}

int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		printf("%.2f\n",getMinRolls(n));
	}
	return 0;
}