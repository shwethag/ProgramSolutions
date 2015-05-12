#include <iostream>
#include <vector>

using namespace std;

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3

*/



class Solution {
	int rows,columns;
public:
	void dfs(vector<vector<char> > &grid, int i,int j){
		grid[i][j] = 'x';
		if(i+1 != rows && grid[i+1][j] != 'x' && grid[i+1][j]!='0')
			dfs(grid,i+1,j);
		if(i-1 != -1 && grid[i-1][j] != 'x' && grid[i-1][j]!='0')
			dfs(grid,i-1,j);
		if(j+1 != columns && grid[i][j+1] != 'x' && grid[i][j+1]!='0')
			dfs(grid,i,j+1);
		if(j-1 != -1 && grid[i][j-1] != 'x' && grid[i][j-1]!='0')
			dfs(grid,i,j-1);

	}
    int numIslands(vector<vector<char> >& grid) {
    	int islandCount = 0;
        rows = grid.size();
        if(rows!=0)
        	columns = grid[0].size();
        for(int i=0;i<rows;i++){
        	for(int j=0;j<columns;j++){
        		if(grid[i][j]!='0' && grid[i][j]!='x'){
        			dfs(grid,i,j);
        			islandCount++;
        		}
        	}
        }
        return islandCount;
    }
};

int main(){
	char r1[] ={"11000"};
	char r2[] ={"11000"};
	char r3[] ={"00100"};
	char r4[] ={"00011"};

	vector<char> row1(r1,r1+5);
	vector<char> row2(r2,r2+5);
	vector<char> row3(r3,r3+5);
	vector<char> row4(r4,r4+5);

	vector<vector<char> > islands;
	islands.push_back(row1);
	islands.push_back(row2);
	islands.push_back(row3);
	islands.push_back(row4);

	Solution s;
	cout<<s.numIslands(islands)<<endl;	

	return 0;
}