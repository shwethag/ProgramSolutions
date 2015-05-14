#include <iostream>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/


// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 && !l2) return l1;
        if(l2 && !l1) return l2;

        ListNode *first = NULL;
        ListNode *cur1 = l1,*cur2 = l2,*cur = first,*tmp;
        while(cur1 && cur2){
        	if(cur1->val < cur2->val){
        		tmp = cur1;
        		
        		cur1 = cur1->next;
        	}else{
        		tmp = cur2;
        		cur2 = cur2->next;
        	}

        	if(cur){
        			cur->next = tmp;
        			cur = tmp;
        	}else{
        		first = tmp;
       			cur = first;
       		}
        }
        if(cur1)
        	cur->next = cur1;
        if(cur2)
        	cur->next = cur2;

        return first;
    }
};

int main(){

	Solution s;
	ListNode *first1=NULL,*first2 = NULL;
	first1 = new ListNode(1);
	first2 = new ListNode(2);

	ListNode *next1,*next2,*tmp1,*tmp2;
	next1 = new ListNode(2);
	tmp1 = first1;
	tmp1->next = next1;

	
	next2 = new ListNode(3);
	tmp2 = first2;
	tmp2->next = next2;

	tmp1 = next1;
	next1 = new ListNode(4);
	tmp1->next = next1;

	tmp2 = next2;
	next2 = new ListNode(4);
	tmp2->next = next2;

	tmp1 = next1;
	next1 = new ListNode(4);
	tmp1->next = next1;

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

	ListNode *nfirst = s.mergeTwoLists(first1,first2);
	tmp1 = nfirst;
	while(tmp1!=NULL){
		cout<<tmp1->val<<"->";
		tmp1 = tmp1->next;
	}
	cout<<endl;
	return 0;
}

