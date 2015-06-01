#include <iostream>

using namespace std;

int main(){

	int t,x,avg,n,s,sum;

	cin>>t;

	while(t--){

		cin>>x>>avg;
		n = (avg-x);
		s = avg*(n+1) - x;
		n--;
		sum = (n * (n+1)) / 2;
		s -= sum;
		cout<<s<<endl;

	}

	return 0;
}