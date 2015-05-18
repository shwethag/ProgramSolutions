#include <iostream>

using namespace std;

/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4,5,6}, reorder it to {1,6,2,5,3,4}. 
*/


/**
 * Definition for singly-linked list.
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	int getLen(ListNode *head){
		int len = 0;
		while(head){
			len++;
			head = head->next;
		}
		return len;
	}

    void reorderList(ListNode* head) {
        int len = getLen(head);
        if(len <=2)
        	return; 
        ListNode *cur = head;
        ListNode *hash[len];
        int i=0;
        while(cur){
        	hash[i] = cur;
        	cur = cur->next;
        	i++;
        }
        i = 0;
        int j=len-1;
        while(i<j){
        	hash[i]->next = hash[j];
        	i++;
        	hash[j]->next = hash[i];
        	j--;
        }
        if(i!=j){
        	j++;
        }
        hash[j]->next = NULL;

	}
};

int main(){
	Solution s;
	ListNode *next,*tmp;
	ListNode *first=NULL;
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

	s.reorderList(first);

	tmp = first;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;
}