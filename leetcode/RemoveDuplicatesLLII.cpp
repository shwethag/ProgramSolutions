#include <iostream>

using namespace std;

/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, 
 leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
    ListNode* deleteDuplicates(ListNode* head) {
       	ListNode *cur = head,*tmp;
       	int val;
       	ListNode *newNode = new ListNode(-1);
       	ListNode *prev = newNode;
       	while(cur!=NULL){
       		val = cur->val;
       		if(cur->next!=NULL && cur->next->val == val){
       			while(cur!=NULL && cur->val==val ){
       				tmp = cur;
       				cur = cur->next;
       				delete tmp;
       			}
       		}else{
       			prev->next = cur;
       			prev = cur;
       			cur = cur->next;
       		}
       		
       	}
       	prev->next = NULL;
       	tmp = newNode;
       	newNode = newNode->next;
       	delete tmp;
       	return newNode;
    }
};

int main(){

	Solution s;
	ListNode *first=NULL;
	ListNode *next,*tmp;
	first = new ListNode(1);

	
	next = new ListNode(1);
	tmp = first;
	tmp->next = next;

	tmp = next;
	next = new ListNode(2);
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
	next = new ListNode(5);
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