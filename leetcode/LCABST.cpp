#include <iostream>
#include <stack>

using namespace std;

/*
  Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and 
w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
 since a node can be a descendant of itself according to the LCA definition.
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
        if(p->val > q->val)
            return lowestCommonAncestor(root,q,p);
        if(root->val >= p->val && root->val <= q->val){
          return root;
        }

        if(p->val >= root->val && q->val >= root->val)
          return lowestCommonAncestor(root->right,p,q);
        else
          return lowestCommonAncestor(root->left,p,q);
    }
};

int main(){

	TreeNode *root = new TreeNode(6);

	root->left = new TreeNode(2);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);

	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(5);

	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);

	
	Solution s;
	TreeNode *node = s.lowestCommonAncestor(root,root->right,root);
  cout<<node->val<<endl;
	
	return 0;
}