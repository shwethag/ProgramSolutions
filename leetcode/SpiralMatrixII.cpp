#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 
*/

class Solution {
	static const int RIGHT = 1;
	static const int LEFT = -1;
	static const int UP = 2;
	static const int DOWN = -2;
public:
    vector<vector<int> > generateMatrix(int n) {
        int size = n*n;
    	int dir = RIGHT;
    	int matrix[n][n];
    	
    	bool visited[n][n];
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			visited[i][j] = false;

    	int i=0,j=0,k=1;
    	while(k <= size){
    		while(dir == RIGHT){
    			matrix[i][j] = k++;
    			visited[i][j] = true;
    			j++;
    			
    			if(j==n || visited[i][j] == true){
    				dir = DOWN;
    				j--;
    				i++;
    			}
    		}
    		if(k > size)
    			break;
    		while(dir == DOWN){
    			matrix[i][j] = k++;
    			visited[i][j] = true;
    			i++;
    			if(i == n || visited[i][j] == true){
    				dir = LEFT;
    				i--;
    				j--;
    			}
    		}
    		if(k > size)
    			break;
    		while(dir == LEFT){
    			matrix[i][j] = k++;
    			visited[i][j] = true;
    			j--;
    			if(j == -1 || visited[i][j] == true){
    				dir = UP;
    				i--;
    				j++;
    			}
    		}
    		if(k > size)
    			break;
    		while(dir == UP){
    			matrix[i][j] = k++;
    			visited[i][j] = true;
    			i--;
    			if(i == -1 || visited[i][j] == true){
    				dir = RIGHT;
    				i++;
    				j++;
    			}
    		}
    	}

         vector<vector<int> > spiral;
        for(int i=0;i<n;i++){
            vector<int> row(matrix[i],matrix[i]+n);
            spiral.push_back(row);
        }
    	return spiral;
        
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    vector<vector<int> > spiral = s.generateMatrix(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<spiral[i][j]<<" ";
        }
        cout<<endl;
    }


	return 0;
}