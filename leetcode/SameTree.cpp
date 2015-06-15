#include <iostream>

using namespace std;

/*
 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 


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
   

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
          return true;
        if(!p || !q)
          return false;
        if(p->val != q->val)
          return false;
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};

int main(){
	
  TreeNode *p,*q;

	p = new TreeNode(2);
	q = new TreeNode(2);

	p->left = new TreeNode(3);
	p->right = new TreeNode(4);

	q->left = new TreeNode(3);
	q->right = new TreeNode(4);


	
	Solution s;

	bool isSym = s.isSameTree(p,q);

	if(isSym)
		cout<<"Same "<<endl;
	else
		cout<<"Not Same"<<endl;
	return 0;
}