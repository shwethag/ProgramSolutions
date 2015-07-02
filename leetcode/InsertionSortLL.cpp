#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next )
        	return head;
        int val;
        ListNode *cur,*min,*prev,*cnode;
        prev = NULL;
        cur = head;
        min = head;

        while(cur!=NULL){
        	min = cur;
        	cnode = cur;
        	while(cnode!=NULL){
        		if(cnode->val < min->val){
        			min = cnode;
        		}
        		cnode = cnode->next;
        	}
        	//remap linkage
        	if(min!=cur){
        		val = cur->val;
        		cur->val = min->val;
        		min->val = val;
        	}
        	cur = cur->next;
        }
        return head;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(1);
	cur = cur->next;

	cur->next = new ListNode(3);
	cur = cur->next;

	cur->next = new ListNode(2);
	cur = cur->next;

	cur->next = new ListNode(5);
	cur = cur->next;

	cur->next = new ListNode(1);

	Solution s;

	head = s.insertionSortList(head);

	cur  = head;
	while(cur!=NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;

	return 0;
}