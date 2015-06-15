#include <iostream>
#include <stack>

using namespace std;

/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
 adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
        -------------
        27 22 26  18

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	
    	if(root == NULL)
    	{
    		if(sum == 0)
    			return true;
    		else
    			return false;
    	}


       	if(root->left == NULL && root->right == NULL){
       		if(sum == root->val)
       			return true;
       		else
       			return false;
       	}
		bool left = false,right=false;
		if(root->left)
			left = hasPathSum(root->left,sum-root->val);
		if(root->right)
			right = hasPathSum(root->right,sum-root->val);
	   	return ( left || right);
    }
};

int main(){

	TreeNode *root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(11);

	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	root->right->right->right = new TreeNode(1);

	Solution s;
	cout<<s.hasPathSum(root,18)<<endl;
	
	return 0;
}