#include <iostream>
#include <vector>


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

    void sumUtil(TreeNode *cur, int &cursum, int num){
      if(cur == NULL)
        return;
      if(!cur->left  && !cur->right){
        num += cur->val;
        cursum += num;
        return;
      }
      num += cur->val;
      if(cur->left)
        sumUtil(cur->left,cursum,num*10);
      if(cur->right)
        sumUtil(cur->right,cursum,num*10);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0; 
        sumUtil(root,sum,0);
        return sum;
    }
};

int main(){

	TreeNode *root = new TreeNode(2);

	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	/*root->left->left = new TreeNode(11);

	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

  root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);*/

	Solution s;
  int sum = s.sumNumbers(root);

	cout<<sum<<endl;
	return 0;
}