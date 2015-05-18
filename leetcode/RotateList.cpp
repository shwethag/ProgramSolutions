#include <iostream>

using namespace std;

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
	int getLen(ListNode *head){
		ListNode *tmp = head;
		int count = 0;
		while(tmp!=NULL)
		{
			count++;
			tmp = tmp->next;
		}
		return count;
	}

    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL)
    		return head;
    	int len = getLen(head);
    	k = k%len;
    	ListNode *fptr,*kptr;
    	kptr = fptr = head;
    	int count = 0;
    	while(count<k){
    		fptr = fptr->next;
    		count++;
    	}
    	while(fptr->next!=NULL){
    		kptr = kptr->next;
    		fptr = fptr->next;
    	}
    	fptr->next = head;
    	ListNode *tmp = kptr->next;
    	kptr->next = NULL;
    	head = tmp;
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

	/*tmp = next;
	next = new ListNode(4);
	tmp->next = next;

	tmp = next;
	next = new ListNode(5);
	tmp->next = next;

	tmp = next;
	next = new ListNode(6);
	tmp->next = next;
*/
	first = s.rotateRight(first,2000000000);

	tmp = first;

	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;

}