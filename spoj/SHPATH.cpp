#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <map>
#define MAX_CITY 10010
#define vvadj vector<vector<pair<int,int> > >

using namespace std;


struct node{
	int index,distance;
	bool visited;
	bool operator()(node const & n1, node const & n2) const{
        return (n1.distance > n2.distance);
    }
};

map<string,int> citymap;
node dist[MAX_CITY];



int getMinDistance(string c1,string c2,int cityCnt,vvadj adjMat){
	int i1 = citymap[c1];
	int i2 = citymap[c2];
	priority_queue<node,vector<node>,node> pq;
	
	for(int i=0;i<=cityCnt;i++){
		dist[i].visited = false;
		dist[i].distance = INT_MAX;
	}
	dist[i1].distance = 0;
	
	pq.push(dist[i1]);
	int mindex,i;
	int len,index,distance,temp;
	while(!pq.empty() && !dist[i2].visited){
		node minnode = pq.top();
		pq.pop();
		mindex = minnode.index;
		if(dist[mindex].visited)
			continue;
		minnode.visited = true;
		len = adjMat[mindex].size();
		for(i=0;i<len;i++){
			index = adjMat[mindex][i].first;
			distance = adjMat[mindex][i].second;
			if(!dist[index].visited && dist[mindex].distance!=INT_MAX){
				temp = distance+dist[mindex].distance;
				if(dist[index].distance > temp){
					dist[index].distance = temp;
					pq.push(dist[index]);
				}
			}
		}
	}
	return dist[i2].distance;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int testcases,cityCnt,neighbourCnt,neigh,cost,paths,i,j;
	string name;
	cin>>testcases;
	string c1,c2;
	vvadj adjMat;
	while(testcases--){
		cin>>cityCnt;
		//adjMat.clear();
		adjMat.resize(cityCnt+1,vector<pair<int,int> >() );
		//adjMat.push_back();
		dist[0].index = 0;
		for(i = 1;i<=cityCnt;i++){
			dist[i].index = i;
			//	adjMat.push_back(vector<pair<int,int> >() );
			cin>>name;
			citymap[name] = i;
			cin>>neighbourCnt;
			for(j=0;j<neighbourCnt;j++){
				cin>>neigh>>cost;
				adjMat[i].push_back(make_pair(neigh,cost));
			}
		}
		cin>>paths;
		for(i=0;i<paths;i++){
			cin>>c1>>c2;
			cout<<getMinDistance(c1,c2,cityCnt,adjMat)<<endl;
		}
	}
	return 0;
}