#include <iostream>
#include <algorithm>

using namespace std;

int a,b,c;
long int steps = 0;

inline void pour(int &cura,int &curb){
	steps++;
	int capacity = b-curb;
	curb =  min(b,cura+curb);
	cura = max(cura - capacity,0);
	
}

int getSteps(int cura,int curb){
	
	while(cura != c || curb != c){
		if(cura == 0){
			cura = a;
			steps++;

		}
		if(curb == b){
			curb = 0;
			steps++;
		}
		pour(cura,curb);
		if(cura == c || curb == c)
			break;
		
	}

	return steps;
	
}

int getGCD(int a,int b){
	if(a < b)
		return getGCD(b,a);
	if(b == 0)
		return a;
	return getGCD(a%b,b);
}

int main(){
	int t;
	cin>>t;

	for(int i=0;i<t;i++){
		cin>>a>>b>>c; 
		steps = 0;
		if(a == c || b == c){
			cout<<"1"<<endl;
			continue;
		}else if(a < c && b < c){
			cout<<"-1"<<endl;
			continue;
		}
		int gcd = getGCD(a,b);
		if(c%gcd != 0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		long int ab = getSteps(0,0);
		int t = a;
			a = b;
			b = t;

		steps = 0;
		long int ba = getSteps(0,0);

		cout<<min(ab,ba)<<endl;
	}
	return 0;
}