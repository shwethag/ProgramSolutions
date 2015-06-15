#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]


*/

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
   

   vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int> > level;
        if(root == NULL)
        	return level;
	    que.push(root);
	    que.push(NULL);
	    vector<int> row;
	    while(!que.empty()){
	    	TreeNode *node = que.front();
	    	que.pop();
	    	if(node == NULL)
	    	{
	    		level.push_back(row);
	    		row.clear();
	    		if(!que.empty())
	    			que.push(NULL);
	    		continue;

	    	}
	    	row.push_back(node->val);
	    	if(node->left)
	    		que.push(node->left);
	    	if(node->right)
	    		que.push(node->right);
    	}
    	return level;
	}
};

int main(){
	
  	TreeNode *root = new TreeNode(1);

	TreeNode *cur = root;

	cur->left = new TreeNode(2);
	cur->right = new TreeNode(2);

	cur->left->left = new TreeNode(3);
	cur->left->right = new TreeNode(4);

	//cur->right->left = new TreeNode(5);
	cur->right->right = new TreeNode(3);
	
	Solution s;

	vector<vector<int> > level = s.levelOrder(root);

	for(int i=0;i<level.size();i++){
		for(int j=0;j<level[i].size();j++){
			cout<<level[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}