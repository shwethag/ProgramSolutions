#include <iostream>
#include <vector>

using namespace std;

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix: 
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/

class Solution {
	static const int RIGHT = 1;
	static const int LEFT = -1;
	static const int UP = 2;
	static const int DOWN = -2;
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	int dir = RIGHT;
    	vector<int> spiral;
    	
    	int rows = matrix.size();
    	if(rows == 0)
    		return spiral;
    	int cols = matrix[0].size();
    	int total = rows*cols;
    	bool visited[rows][cols];
    	for(int i=0;i<rows;i++)
    		for(int j=0;j<cols;j++)
    			visited[i][j] = false;

    	int i=0,j=0;
    	while(total >0){
    		while(dir == RIGHT){
    			spiral.push_back(matrix[i][j]);
    			visited[i][j] = true;
    			j++;
    			total--;
    			if(j==cols || visited[i][j] == true){
    				dir = DOWN;
    				j--;
    				i++;
    			}
    		}
    		if(total <= 0)
    			break;
    		while(dir == DOWN){
    			spiral.push_back(matrix[i][j]);
    			visited[i][j] = true;
    			i++;
    			total--;
    			if(i == rows || visited[i][j] == true){
    				dir = LEFT;
    				i--;
    				j--;
    			}
    		}
    		if(total <= 0)
    			break;
    		while(dir == LEFT){
    			spiral.push_back(matrix[i][j]);
    			visited[i][j] = true;
    			j--;
    			total--;
    			if(j == -1 || visited[i][j] == true){
    				dir = UP;
    				i--;
    				j++;
    			}
    		}
    		if(total <= 0)
    			break;
    		while(dir == UP){
    			spiral.push_back(matrix[i][j]);
    			visited[i][j] = true;
    			i--;
    			total--;
    			if(i == -1 || visited[i][j] == true){
    				dir = RIGHT;
    				i++;
    				j++;
    			}
    		}


    	}
    	return spiral;
        
    }
};

int main(){
	vector<vector<int> > matrix;
	int r1[] = {1,2,3};
	vector<int> row1(r1,r1+3);
	matrix.push_back(row1);

	int r2[] = {4,5,6};
	vector<int> row2(r2,r2+3);
	matrix.push_back(row2);

	int r3[] = {7,8,9};
	vector<int> row3(r3,r3+3);
	matrix.push_back(row3);
	

	Solution s ;
	vector<vector<int> > mat;
	vector<int> spiral = s.spiralOrder(mat);

	for(int i=0;i<spiral.size();i++)
		cout<<spiral[i]<<" ";
	cout<<endl;

	return 0;
}