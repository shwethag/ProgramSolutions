#include <iostream>

using namespace std;

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *cur = head,*tmp,*prev;
    	int cval;
    	while(cur!=NULL){
			cval = cur->val;
			prev = cur;
			cur = cur->next;
			while(cur!= NULL && cur->val == cval){
				tmp = cur;
				cur = cur->next;
				delete tmp;
			}    
			prev->next = cur;		
    	}
        return head;
    }
};

int main(){

	Solution s;
	ListNode *first=NULL;
	first = new ListNode(2);

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
	next = new ListNode(4);
	tmp->next = next;

	tmp = next;
	next = new ListNode(4);
	tmp->next = next;

	tmp = first;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	first = s.deleteDuplicates(first);

	tmp = first;

	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;
}