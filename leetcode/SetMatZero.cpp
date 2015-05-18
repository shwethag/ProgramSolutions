#include <iostream>
#include <vector>

using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
*/

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
    	if(matrix.size() == 0)
    		return;
    	int rlen = matrix.size();
    	int clen = matrix[0].size();

    	bool hashRow[rlen];
    	bool hashCol[clen];

    	for(int i=0;i<rlen;i++)
    		hashRow[i] = false;
    	for(int i=0;i<clen;i++)
    		hashCol[i] = false;

    	for(int i=0;i<rlen;i++)
    	{
    		for(int j=0;j<clen;j++){
    			if(matrix[i][j] == 0){
    				if(!hashRow[i]){
    					hashRow[i] = true;
    				}

    				if(!hashCol[j]){
    					hashCol[j] = true;
    				}
    			}	
    		}
    	}

    	for(int i=0;i<rlen;i++){
    		if(hashRow[i]){
    			for(int k=0;k<clen;k++)
    				matrix[i][k] = 0;
    		}
    	}

    	for(int i=0;i<clen;i++){
    		if(hashCol[i]){
    			for(int k=0;k<rlen;k++)
    				matrix[k][i] = 0;
    		}
    	}


        
    }
};

int main(){
	int r1[]= {0,1,1,1,0};
	int r2[]= {1,0,1,1,1};
	int r3[]= {1,1,1,1,1};
	vector<int> row1(r1,r1+5);
	vector<int> row2(r2,r2+5);
	vector<int> row3(r3,r3+5);

	vector<vector<int> > matrix;
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);

	Solution s;

	s.setZeroes(matrix);


	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

