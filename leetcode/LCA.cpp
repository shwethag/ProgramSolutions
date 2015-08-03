#include <iostream>
#include <stack>

using namespace std;

/*
   Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
          return NULL;
        if(root == p || root == q)
          return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left && right)
          return root;
        return left?left : right;
    }

    bool findNode(TreeNode *root,int a){
      if(!root)
        return false;
      if(root->val == a)
        return true;
      return (findNode(root->left,a) || findNode(root->right,a));
    }

     TreeNode* lcaUtil(TreeNode* root, int p, int q) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!root)
          return NULL;
       if(root->val == p || root->val == q)
          return root;
        TreeNode* left = lcaUtil(root->left,p,q);
        TreeNode* right = lcaUtil(root->right,p,q);
        if(left && right)
          return root;
        return left?left:right;

    }

    int lca(TreeNode* root, int p, int q) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode *node = lcaUtil(root,p,q);
    if(!node)
      return -1;
    bool n1,n2;
    n1 = findNode(node,p);
    n2 = findNode(node,q);
    if(n1 && n2)
      return node->val;
    return -1;

  }

};

int main(){

	TreeNode *root = new TreeNode(3);

	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);

	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	
	Solution s;
	TreeNode *node = s.lowestCommonAncestor(root,root->right->left,root->right->right);
  int lc = s.lca(root,6,8);
  cout<<lc<<endl;
	
	return 0;
}