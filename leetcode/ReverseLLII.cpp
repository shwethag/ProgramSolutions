#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
*/

/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
*/

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m == n)
			return head;
    	ListNode *tmp = NULL,*cur = head,*next,*endptr,*stPtr=NULL;
    	int cnt = 1;
    	while(cnt<m){
    		cnt++;
    		stPtr = cur;
    		cur = cur->next;
    	}
    	endptr = cur;
    	cnt--;
    	while(cnt<n){
    		cnt++;
    		next = cur->next;
    		cur->next = tmp;
    		tmp = cur;
    		cur = next;
    	}
    	if(stPtr)
    		stPtr->next = tmp;
    	endptr->next = next;	
    	if(endptr == head)
    		return tmp;
    	return head;
        
    }
};

int main(){
	Solution s;
	ListNode *first=NULL;
	first = new ListNode(1);

	ListNode *next,*tmp;
	next = new ListNode(2);
	tmp = first;
	tmp->next = next;

	tmp = next;
	next = new ListNode(3);
	tmp->next = next;

	tmp = next;
	next = new ListNode(4);
	tmp->next = next;

	tmp = next;
	next = new ListNode(5);
	tmp->next = next;

	tmp = next;
	next = new ListNode(6);
	tmp->next = next;

	

	first = s.reverseBetween(first,3,5);

	tmp = first;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;
}