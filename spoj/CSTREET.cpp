#include <iostream>
#include <algorithm>

#define CNT 1010

using namespace std;

bool hash[CNT];
bool matrix[CNT][CNT];
bool visited[CNT];


class path{
public:
	int a,b,c;
};

bool comp(path p1,path p2){
	return (p1.c < p2.c);
}

void clearMat(int mainCnt){
	for(int i=0;i<=mainCnt;i++){
		for(int j=0;j<=mainCnt;j++){
			matrix[i][j] = false;
		}
	}
}

bool isReachable(int src,int dest,int mcnt){
	visited[src] = true;
	//cout<<"src "<<src<<" dest "<<dest<<" "<<matrix[src][dest]<<endl;
	if(matrix[src][dest]){
		return true;
	}
	for(int i=1;i<=mcnt;i++){
		//cout<<"mat-->"<<src<<" "<<i<<" "<<matrix[src][i]<<" "<<visited[i]<<endl;
		if(matrix[src][i] && !visited[i]){
			bool isRch = isReachable(i,dest,mcnt);
			if(isRch)
				return true;
		}
	}
	return false;
}

int main(){
	int t, price_1furlong, mainCnt, streetCnt,a,b,c;
	cin>>t;
	while(t--){
		cin>>price_1furlong>>mainCnt>>streetCnt;


		for(int i=0;i<=mainCnt;i++){
			hash[i] = false;
			visited[i] = false;
		}
		clearMat(mainCnt);
		
		path p_arr[streetCnt];
		for(int i=0;i<streetCnt;i++){
			cin>>a>>b>>c;
			path p;
			p.a = a;
			p.b = b;
			p.c = c*price_1furlong;
			p_arr[i] = p;
		}
		sort(p_arr,p_arr+streetCnt,comp);

		int curCnt = 0,curCost = 0;
		int i=0;
		while(curCnt<mainCnt){
			path p = p_arr[i];
			for(int j=1;j<=mainCnt;j++){
				visited[j] = false;
			}
			bool res =  false;
			if(hash[p.a] && hash[p.b] && (res = isReachable(p.a,p.b,mainCnt))){
				i++;
				//cout<<p.a<<" "<<p.b<<" "<<p.c<<" "<<res<<" "<<hash[p.a]<<" "<<" "<<hash[p.b]<<endl;
				continue;
			}
			//cout<<p.a<<" "<<p.b<<" "<<p.c<<" "<<res<<" "<<hash[p.a]<<" "<<" "<<hash[p.b]<<endl;
			//cout<<p.a<<" "<<p.b<<" "<<p.c<<endl;
			curCost+= p.c;
			matrix[p.a][p.b] = true;
			matrix[p.b][p.a] = true;
			if(!hash[p.a]){
				curCnt++;
				hash[p.a] = true;
			}

			if(!hash[p.b]){
				curCnt++;
				hash[p.b] = true;
			}
			
			i++;
		}

		
		cout<<curCost<<endl;

	}
	return 0;
}