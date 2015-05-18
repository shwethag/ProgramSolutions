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
    	if(!l1 && !l2) return NULL;
        if(l1 && !l2) return l1;
        if(l2 && !l1) return l2;

       	ListNode *tmp;
       	if(l1->val < l2->val){
       		tmp = l1;
       		tmp->next = mergeTwoLists(l1->next,l2);
       	}
       	else{
       		tmp = l2;
       		tmp->next = mergeTwoLists(l1,l2->next);
       	}

        return tmp;
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

	ListNode *nfirst = s.mergeTwoLists(NULL,NULL);
	tmp1 = nfirst;
	while(tmp1!=NULL){
		cout<<tmp1->val<<"->";
		tmp1 = tmp1->next;
	}
	cout<<endl;
	return 0;
}

