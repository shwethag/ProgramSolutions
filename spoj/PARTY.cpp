#include <iostream>
#include <climits>

#define MAX_PARTY 110
#define MAX_BUDGET 510

using namespace std;
int party_cost[MAX_PARTY];
int fun[MAX_PARTY];
int costmat[MAX_PARTY][MAX_BUDGET];
int funmat[MAX_PARTY][MAX_BUDGET];
int maxCost,maxFun;

int computeMaxCostFun(int p,int b,int &cost){
	if(p == 0 || b == 0)
		return 0;

	if(funmat[p][b] != 0){
		return funmat[p][b];
	}
	int c1 = 0,c2 = 0;
	int o1 = computeMaxCostFun(p-1,b, c1);
	c1 = costmat[p-1][b];
	int o2 = -1;
	if(party_cost[p] <= b){
		
			o2 = computeMaxCostFun(p-1,b - party_cost[p],c2) + fun[p];
			c2 = costmat[p-1][b - party_cost[p]] + party_cost[p];
		
	}
	if(o1 == o2){
		if(c1 < c2){
			funmat[p][b] = o1;
			cost = c1;
		}else{
			funmat[p][b] = o2;
			cost = c2;
		}
	}

	else if(o1 > o2){
		
		funmat[p][b] = o1;
		cost = c1;
	}else{
		funmat[p][b] = o2;
		cost = c2;
	}
		

	costmat[p][b] = cost;
	
	return funmat[p][b];

}

int main(){
	int budget, pcount;
	while(true){
		cin>>budget>>pcount;
		if(budget == 0 && pcount == 0)
			break;
		for(int i=1;i<=pcount;i++){
			cin>>party_cost[i]>>fun[i];
		}

		for(int i=0;i<=pcount;i++){
			for(int j=0;j<=budget;j++){
				costmat[i][j] = 0;
				funmat[i][j] = 0;
			}
		}
		maxCost = maxFun = 0;
		int optimal = computeMaxCostFun(pcount,budget,maxCost);
		cout<<maxCost<<" "<<optimal<<endl;
	}
	return 0;
}