#include <iostream>

using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.


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
    bool isMirror(TreeNode *left, TreeNode *right){
      if(!left && !right)
        return true;
      if(!left || !right)
        return false;
      if(left->val != right->val)
        return false;
      return (isMirror(left->left,right->right) && isMirror(left->right,right->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        	return true;
        return isMirror(root->left,root->right);
    }
};

int main(){
	TreeNode *root = new TreeNode(1);

	TreeNode *cur = root;

	cur->left = new TreeNode(2);
	cur->right = new TreeNode(2);

	cur->left->left = new TreeNode(3);
	cur->left->right = new TreeNode(4);

	cur->right->left = new TreeNode(4);
	cur->right->right = new TreeNode(3);


	
	Solution s;

	bool isSym = s.isSymmetric(root);

	if(isSym)
		cout<<"Symmetric "<<endl;
	else
		cout<<"Not symmetric"<<endl;
	return 0;
}