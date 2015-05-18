#include <iostream>

using namespace std;

/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4->5, you should return the list as 2->1->4->3->5.

Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed. 
*/
/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head,*tmp=NULL,*next=NULL;
        while(cur!=NULL && (tmp = cur->next)!=NULL){
        	next = tmp->next;
        	tmp->next = cur;

        	if(cur == head){
        		head = tmp;
        	}
        	
        	if(next!=NULL && next->next != NULL){
        		cur->next = next->next;
        	}
        	else{
        		cur->next = next;
        		break;
        	}
        	cur = next;
        }
        if(next!=NULL)
        	cur->next = next;

        return head;
    }
};

int main(){

	Solution s;
	ListNode *first=NULL;
	ListNode *next,*tmp;
	first = new ListNode(1);

	
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

	first = s.swapPairs(first);

	tmp = first;

	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;
}