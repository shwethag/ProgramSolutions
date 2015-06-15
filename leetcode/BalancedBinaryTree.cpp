#include <iostream>
#include <cmath>

using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree
 in which the depth of the two subtrees of every node never differ by more than 1. 

     		    5
             /    \
            4      8
           / \    / \
          11  15 13  4
         /  \      \
        7    2      1
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

	int depth(TreeNode *root){
		if(!root)
			return 0;
		int leftDepth = depth(root->left);
		int rightDepth = depth(root->right);
		if(leftDepth == -1 || rightDepth == -1)
			return -1;
		if(abs(leftDepth-rightDepth) > 1)
			return -1;
		return 1 + max(leftDepth,rightDepth);
	}

   bool isBalanced(TreeNode* root) {
        if(!root)
        	return true;
        int d = depth(root);
        if(d == -1)
        	return false;
        return true;
    }
};

int main(){
	TreeNode *root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(11);
	root->left->right = new TreeNode(15);

	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	root->right->right->right = new TreeNode(1);

	Solution s;

	cout<<s.isBalanced(root)<<endl;

	return 0;
}

