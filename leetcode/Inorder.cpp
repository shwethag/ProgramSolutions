#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
	vector<int> inorder;
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if(root == NULL){
        return inorder;
      }
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);

        return inorder;
    }
};

int main(){
	TreeNode *root = new TreeNode(3);

	TreeNode *cur = root;

	cur->left = new TreeNode(9);
	cur->right = new TreeNode(20);

	cur = cur->left;

	cur->left = new TreeNode(15);
	cur->right = new TreeNode(7);

	Solution s;

	vector<int> inorder = s.inorderTraversal(root);
	cout<<"[ ";
		
	for(int j=0;j<inorder.size();j++){
		cout<<inorder[j]<<" ";
	}
	
	cout<<"]"<<endl;
	return 0;
}