#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    
    
    
    bool isValid(int r,int c){
        if(r < 0 || c < 0) return false;
        return true;
    }

    int calculateMinimumHP(vector<vector<int> >& A) {
        int r = A.size();
        if(!r) return 0;
        int c = A[0].size();
        vector<vector<int> > dp(r,vector<int>(c,0));
        vector<vector<int> > cost(r,vector<int>(c,0));
        int minhealth = 0,cur_health = 0,left,top,val,l1,l2;
        for(int i = 0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!isValid(i-1,j) && !isValid(i,j-1)){
                    if(A[i][j] < 0){
                        dp[i][j] =  0;
                        cost[i][j] = -A[i][j];
                       
                    }else{
                        dp[i][j] = A[i][j];
                        
                    }
                }else{
                    left = top = A[i][j];
                    if(isValid(i-1,j)){
                        top = dp[i-1][j] + A[i][j];
                    }
                    if(isValid(i,j-1)){
                        left = dp[i][j-1] + A[i][j];
                    }
                  // cout<<left<<" "<<top<<endl;
                    if(!isValid(i-1,j))
                    {
                    	int fac = (left < 0)?-left : 0;
                    	cost[i][j] = cost[i][j-1] + fac;
                    	dp[i][j] = (left < 0)?0:left;
                    }
                    else if(!isValid(i,j-1)){
                    	int fac = (top < 0)?-top : 0;
                    	cost[i][j] = cost[i-1][j] + fac;
                    	dp[i][j] = (top < 0)?0:top;
                    }
                    else{
                        //val = (left < 0)? ((top < 0 )? max(left,top):top):(top >= 0)? min(left,top):left;
                    	l1 = (left < 0)?-left : 0;
                    	l2 = (top < 0)?-top : 0;
                        val = (cost[i-1][j]+l2 < cost[i][j-1]+l1)?top:left;
                       	cout<<val<<" "<<left<<" "<<top<<" " <<l1<<" " <<l2<<endl;
                       	int fac = (val < 0)?-val : 0;
                        cost[i][j] = min((cost[i-1][j]+l2),(cost[i][j-1]+l1));
                        dp[i][j] = (val<0)?0:val;
                    	
                    }
                    
                }
            }
        }
       	
        for(int i=0;i<r;i++){
       		for(int j=0;j<c;j++){
       			cout<<dp[i][j]<<" ";
       		}
       		cout<<endl;
       	}
       	cout<<"-----------------------"<<endl;
       	for(int i=0;i<r;i++){
       		for(int j=0;j<c;j++){
       			cout<<cost[i][j]<<" ";
       		}
       		cout<<endl;
       	}

        

        return cost[r-1][c-1]+1;
        
    }
};

int main(){

	/*int a[] = {3,-20,30};
	int b[] = {-3,4,0};
	[[1,-3,3],[0,-2,0],[-3,-3,-3]]
*/
	int a[] = {1,-3,3};
	int b[] = {0,-2,0};
	int c[] = {-3,-3,-3};

	vector<vector<int> > v;
	v.push_back(vector<int> (a,a+3));
	v.push_back(vector<int> (b,b+3));
	v.push_back(vector<int> (c,c+3));

	Solution s;

	cout<<s.calculateMinimumHP(v)<<endl;

	return 0;
}