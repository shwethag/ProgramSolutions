#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   	  3
     / \
    9  20
   / \
 15  7

return [15,7,9,20,3].

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
	vector<int> postorder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
      if(root == NULL){
        return postorder;
      }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        postorder.push_back(root->val);
       
        return postorder;
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

	vector<int> postorder = s.postorderTraversal(root);
	cout<<"[ ";
		
	for(int j=0;j<postorder.size();j++){
		cout<<postorder[j]<<" ";
	}
	
	cout<<"]"<<endl;
	return 0;
}