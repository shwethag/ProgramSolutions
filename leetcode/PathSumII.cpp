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
    void psumUtil(vector<vector<int> > &res, vector<int> nums,int cursum, TreeNode *node,int sum){
        if(node == NULL){
          return;
        }
        cursum += node->val;
        nums.push_back(node->val);
        if(!node->left && !node->right){
          if(cursum == sum)
            res.push_back(nums);
          return;
        }
        psumUtil(res,nums,cursum,node->left,sum);
        psumUtil(res,nums,cursum,node->right,sum);


    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> nums;
        psumUtil(res,nums,0,root,sum);
        return res;
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

  root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	Solution s;
  vector<vector<int> > psum = s.pathSum(root,22);

	for(int i=0;i< psum.size();i++){
    for(int j=0;j<psum[i].size();j++){
      cout<<psum[i][j]<<" ";
    }
    cout<<endl;
  }
	
	return 0;
}