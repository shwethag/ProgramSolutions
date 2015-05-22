#include <iostream>
#include <climits>
#include <queue>
#define MAX_CITY 10010

using namespace std;


struct node{
	int index,distance;
	bool visited;
	bool operator()(node const & n1, node const & n2)const {

        return (n1.distance > n2.distance);
    }
};

int matrix[MAX_CITY][MAX_CITY];
node dist[MAX_CITY];


void clearMat(int vertices){
	for(int i=0;i<=vertices;i++){
		for(int j=0;j<=vertices;j++){
			matrix[i][j] = INT_MAX ;
		}
	}
}

void clearDist(int vertices){
	for(int i=0;i<=vertices;i++){
		dist[i].index = i;
		dist[i].distance = INT_MAX;//matrix[i1][i];
		dist[i].visited = false;
	}
}



int getMinDistance(int i1,int i2,int vertices){
	//cout<<i1<<" "<<i2<<endl;
	

	dist[i1].distance = 0;
	matrix[i1][i1] = 0;
	priority_queue<node,vector<node>,node> pq;
	pq.push(dist[i1]);	
	while(!pq.empty() && !dist[i2].visited){
		node minnode = pq.top();
		pq.pop();
		int mindex = minnode.index;
		if(mindex == 0 || minnode.visited)
			continue;
		minnode.visited = true;
		for(int i=1;i<=vertices;i++){
			if(!dist[i].visited && matrix[mindex][i]!= INT_MAX && dist[mindex].distance!=INT_MAX ){
				int temp = matrix[mindex][i]+dist[mindex].distance;
				if(temp >= 0 && dist[i].distance > temp){
					dist[i].distance = temp;
					pq.push(dist[i]);
				}
			}
		}
			
	}
	/*cout<<"----------------------------"<<endl;
	for(int i=0;i<vertices;i++){
		cout<<dist[i].distance<<endl;
	}*/
	return dist[i2].distance;
}

void printmat(int vertices){
	for(int i=0;i<=vertices;i++){
		for(int j=0;j<=vertices;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int testcases,vertices,cost,edges;
	cin>>testcases;
	int e1,e2;
	while(testcases--){
		cin>>vertices>>edges;
		clearMat(vertices);
		clearDist(vertices);
		
		for(int i = 0;i<edges;i++){
			cin>>e1>>e2>>cost;
			matrix[e1][e2] = cost;
		}
		cin>>e1>>e2;
		int dist = getMinDistance(e1,e2,vertices);
		if(dist == INT_MAX)
			cout<<"NO"<<endl;
		else
			cout<<dist<<endl;
	}
	return 0;
}