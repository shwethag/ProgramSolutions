#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

*/

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
	bool isLeft;
public:
	Solution(){
		isLeft = true;
	}
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int> > zigzag;
    	if(root == NULL)
    		return zigzag;
    	stack<TreeNode*> que;
    	stack<TreeNode*> stck;
    	
    	vector<int> vals;
    	vals.push_back(root->val);
    	zigzag.push_back(vals);
    	stck.push(root);
    	isLeft = !isLeft;
    	int cnt = 0,level = 1;
    	vals.clear();
    	while(true){
    		if(stck.empty() && que.empty() )
    			break;
    		TreeNode *node;
    		if(isLeft){
    			if(que.empty()){
    				isLeft = !isLeft;
    				level = level*2;
    				cnt = 0;
    				if(vals.size()>0)
    					zigzag.push_back(vals);
    				vals.clear();
    				continue;
    			}
    			node = que.top();
    			que.pop();
	    		if(node->left){
	    			vals.push_back(node->left->val);
	    			stck.push(node->left);
	    		}
	    		if(node->right){
	    			vals.push_back(node->right->val);
	    			stck.push(node->right);
	    		}
	    		
	    			
	    	}else{
	    		if(stck.empty()){
    				isLeft = !isLeft;
    				level = level*2;
    				cnt = 0;
    				if(vals.size()>0)
    					zigzag.push_back(vals);
    				vals.clear();
    				continue;
    			}
	    		node = stck.top();
	    		stck.pop();
	    		if(node->right){
	    			vals.push_back(node->right->val);
	    			que.push(node->right);
	    		}
	    		if(node->left){
	    			que.push(node->left);
	    			vals.push_back(node->left->val);
	    		}
	    			
	    	}
    		cnt+=2;
    		if(cnt == level*2){
    			isLeft = !isLeft;
    			level = level*2;
    			cnt = 0;
    			if(vals.size()>0)
    				zigzag.push_back(vals);
    			vals.clear();
    		}
    	}
    	return zigzag;
    }
};

int main(){
	TreeNode *root = new TreeNode(0);

	TreeNode *cur = root;
	TreeNode *prev = cur;
	cur->left = new TreeNode(2);
	cur->right = new TreeNode(3);

	
	cur = cur->left;

	cur->left = new TreeNode(4);
	cur->right = new TreeNode(5);

	cur = prev->right;

	cur->left = new TreeNode(6);
	cur->right = new TreeNode(7);

	cur = prev->left;

	cur->left->left = new TreeNode(8);
	cur->left->right = new TreeNode(9);
	cur->right->left = new TreeNode(10);
	cur->right->right = new TreeNode(11);

	cur =  prev->right;
	cur->left->left = new TreeNode(12);
	cur->left->right = new TreeNode(13);
	cur->right->left = new TreeNode(14);
	cur->right->right = new TreeNode(15);

	/*cur->left = new TreeNode(-4);
	cur->right = new TreeNode(-3);

	cur->left->right = new TreeNode(-1);
	cur->right->left = new TreeNode(8);

	cur->left->right->right = new TreeNode(3);
	cur->right->left->right = new TreeNode(-9);

	cur->left->right->right->left = new TreeNode(-2);
	cur->right->left->right->left = new TreeNode(4);
*/


	Solution s;

	vector<vector<int> > zigzag = s.zigzagLevelOrder(root);
	cout<<"["<<endl;
		
	for(int i=0;i<zigzag.size();i++){
		cout<<"[";
			for(int j=0;j<zigzag[i].size();j++){
				cout<<zigzag[i][j]<<" ";
			}
		cout<<"]"<<endl;

	}
	cout<<"]"<<endl;
	return 0;
}