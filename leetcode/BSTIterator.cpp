#include <iostream>
#include <stack>

using namespace std;

/*
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
 where h is the height of the tree. 
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

class BSTIterator {
	stack<TreeNode *> stck;
public:
    BSTIterator(TreeNode *root) {
        TreeNode * cur = root;
        while(cur!=NULL){
        	stck.push(cur);
        	cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	if(stck.empty())
    		return false;
    	return true;
        
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur =  stck.top();
        int val = cur->val;
        stck.pop();

        cur = cur->right;
        while(cur!=NULL){
        	stck.push(cur);
        	cur = cur->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
	
	TreeNode *root = new TreeNode(15);

	TreeNode *cur = root;

	cur->left = new TreeNode(10);
	cur->right = new TreeNode(20);

	cur = cur->left;

	cur->left = new TreeNode(5);
	cur->right = new TreeNode(14);

 	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) 
 		cout << i.next()<<endl;

 	cout<<endl;


	return 0;
}
