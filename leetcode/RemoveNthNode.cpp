#include <iostream>

using namespace std;

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head == NULL || n == 0)
    		return head;
        ListNode *p1,*p2;
        p1 = head;
        int step =0;
        while(p1!=NULL && step < n ){
        	step++;
        	p1=p1->next;
        }
        p2 = head;
        ListNode *p2_prev = NULL;
        while(p1!=NULL){
        	p1 = p1->next;
        	p2_prev = p2;
        	p2 = p2->next;
        }
        ListNode *tmp;
        if(p2 == head){
        	tmp = p2;
        	p2 = p2->next;
        	delete tmp;
        	return p2;
        }else{
        	tmp = p2;
        	p2_prev->next = p2->next;
        	delete p2;
        	return head;
        }
    }
};

int main(){
	ListNode *first;
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

	/*tmp = next;
	next = new ListNode(6);
	tmp->next = next;
*/
	Solution s;
	first = s.removeNthFromEnd(first,2);

	tmp = first;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

}