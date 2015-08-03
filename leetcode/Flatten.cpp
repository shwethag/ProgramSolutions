#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
      
       if(root == NULL)
        return;
        if(!root->left && !root->right)
            return;
          TreeNode *prev = root;
      stack<TreeNode *> stck;
      stck.push(root);
      while(!stck.empty()){
        TreeNode * cur = stck.top();
        stck.pop();
        if(cur->right)
           stck.push(cur->right);
        if(cur->left)
           stck.push(cur->left);
         prev->right = cur;
         prev->left = NULL;
         prev = cur;
      }
        
      
    }

};

void inorder(TreeNode *root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){

	/*
		3
		/\
	    9  20
	    /\
	   15 7
	*/
	TreeNode *root = new TreeNode(3);

	TreeNode *cur = root;

	cur->left = new TreeNode(9);
	cur->right = new TreeNode(20);

	cur = cur->left;

	cur->left = new TreeNode(15);
	cur->right = new TreeNode(7);

	Solution s;

	s.flatten(root);
	inorder(root);
	cout<<endl;


	return 0;
}
