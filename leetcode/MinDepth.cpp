#include <iostream>
#include <queue>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
              5
             / \
            4   8
           /   / \
          11  13  4
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


   int minDepth(TreeNode* root) {
      if(!root)
        return 0;
      queue<TreeNode *> que;
      que.push(root);
      que.push(NULL);
      int level = 1;
      while(!que.empty()){
        TreeNode *node = que.front();
        que.pop();
        if(node == NULL){
          level++;
          if(!que.empty()){
            que.push(NULL);
          }
          continue;
        }

        if(!node->left && !node->right){
          return level;
        }
        if(node->left)
          que.push(node->left);
        if(node->right)
          que.push(node->right);
      }
      return level;
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
	cout<<s.minDepth(root)<<endl;
	
	return 0;
}