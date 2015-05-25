#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.

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
	vector<int> preorder;
public:
    vector<int> preorderTraversal(TreeNode* root) {
      if(root == NULL)
        return preorder;
      stack<TreeNode *> stck;
      stck.push(root);
      while(!stck.empty()){
        TreeNode * cur = stck.top();
        preorder.push_back(cur->val);
        stck.pop();
        if(cur->right)
           stck.push(cur->right);
        if(cur->left)
           stck.push(cur->left);
        

      }

      return preorder;
    }
};

int main(){
	TreeNode *root = new TreeNode(3);

	/*TreeNode *cur = root;

	cur->left = new TreeNode(9);
	cur->right = new TreeNode(20);

	cur = cur->left;

	cur->left = new TreeNode(15);
	cur->right = new TreeNode(7);*/

	Solution s;

	vector<int> preorder = s.preorderTraversal(root);
	cout<<"[ ";
		
	for(int j=0;j<preorder.size();j++){
		cout<<preorder[j]<<" ";
	}
	
	cout<<"]"<<endl;
	return 0;
}