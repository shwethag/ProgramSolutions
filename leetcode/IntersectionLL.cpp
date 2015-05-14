#include <iostream>

using namespace std;


/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    	int len1 = getLength(headA);
    	int len2 = getLength(headB);
    	ListNode *cur1 = headA, *cur2 = headB;
    	int diff;
    	if(len1 > len2){
    		diff = len1-len2;
    		int cnt = 0;
    		while(cnt < diff){
    			cur1 = cur1->next;
    			cnt++;
    		}
    	}else if(len2 > len1){
    		diff = len2-len1;
    		int cnt = 0;
    		while(cnt < diff){
    			cur2 = cur2->next;
    			cnt++;
    		}
    	}

    	while(cur1 != cur2){
    		cur1 = cur1->next;
    		cur2 = cur2->next;
    	}
    	if(cur1 != NULL && cur1 == cur2)
    		return cur1;
    	return NULL;
        
    }

    int getLength(ListNode *head){
    	ListNode *cur = head;
    	int len = 0;
    	while(cur!=NULL){
    		len++;
    		cur = cur->next;
    	}
    	return len;
    }
};

int main(){
	Solution s;
	ListNode *first1=NULL,*first2 = NULL;
	first1 = new ListNode(1);
	first2 = new ListNode(2);

	ListNode *next1,*next2,*tmp1,*tmp2,*in;
	next1 = new ListNode(2);
	tmp1 = first1;
	tmp1->next = next1;


	
	next2 = new ListNode(3);
	tmp2 = first2;
	tmp2->next = next2;

	in = tmp2;

	tmp1 = next1;
	next1 = new ListNode(4);
	tmp1->next = next1;

	tmp2 = next2;
	next2 = new ListNode(4);
	tmp2->next = next2;

	tmp1 = next1;
	next1 = new ListNode(4);
	tmp1->next = next1;

	tmp1 = next1;
	tmp1->next = in;


	tmp1 = first1;
	while(tmp1!=NULL){
		cout<<tmp1->val<<"->";
		tmp1 = tmp1->next;
	}
	cout<<endl;


	tmp2 = first2;
	while(tmp2!=NULL){
		cout<<tmp2->val<<"->";
		tmp2 = tmp2->next;
	}
	cout<<endl;



	ListNode *nfirst = s.getIntersectionNode(first1,first2);
	tmp1 = nfirst;
	while(tmp1!=NULL){
		cout<<tmp1->val<<"->";
		tmp1 = tmp1->next;
	}
	cout<<endl;
	return 0;
}

