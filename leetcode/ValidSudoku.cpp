#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated. 
*/

class Solution {
public: 
	bool checkisValid(vector<char> content){
		map<char,bool> numMap;
		for(int i=0;i<9;i++){
			if((content[i]< '1' || content[i] >'9') && content[i]!='.'){
				return false;
			}
			if(numMap[content[i]] && content[i]!='.')
				return false;
			numMap[content[i]] = true;
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char> > &board) {
        int rows,cols;
        rows = cols = 9;

        for(int i=0;i<9;i++){
        	if(!checkisValid(board[i])){
        		return false;
        	}
        }

        vector<char> col;
        for(int i=0;i<9;i++){
        	for(int j=0;j<9;j++){
        		col.push_back(board[j][i]);
        	}
        	if(!checkisValid(col)){
        		return false;
        	}
        	col.clear();
        }

        vector<char> box;
        for(int t=0;t<3;t++){
	        for(int k=0;k<3;k++){
	        	box.clear();
	        	for(int i=0;i<3;i++){
	        		for(int j=0;j<3;j++){
	        			box.push_back(board[i+3*t][j+3*k]);
	        		}
	        	}
	        	if(!checkisValid(box)){
	        		return false;
	        	}
	        }
	    }
        return true;

    }
};

int main(){
	char r0[] = {".87654321"};
	vector<char> row0(r0,r0+9);

	char r1[] = {"2........"};
	vector<char> row1(r1,r1+9);

	char r2[] = {"3........"};
	vector<char> row2(r2,r2+9);

	char r3[] = {"4........"};
	vector<char> row3(r3,r3+9);

	char r4[] = {"5........"};
	vector<char> row4(r4,r4+9);

	char r5[] = {"6........"};
	vector<char> row5(r5,r5+9);

	char r6[] = {"7........"};
	vector<char> row6(r6,r6+9);

	char r7[] = {"8........"};
	vector<char> row7(r7,r7+9);

	char r8[] = {"9........"};
	vector<char> row8(r8,r8+9);

	vector<vector<char> > board;

	board.push_back(row0);
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);
	board.push_back(row4);
	board.push_back(row5);
	board.push_back(row6);
	board.push_back(row7);
	board.push_back(row8);

	Solution s;
	if(s.isValidSudoku(board)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}

	return 0;
}