#include <iostream>

using namespace std;
/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
*/

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode *tmp = head,*prev=NULL;
    	while(tmp!=NULL){
    		if(tmp->val == val){
    			if(tmp == head){
    				head = head->next;
    				delete tmp;
    				prev = NULL;
    				tmp = head;
    			}else{
    				if(prev!=NULL){
    					prev->next = tmp->next;
    					delete tmp;
    					tmp = prev->next;
    				}
    			}
    		}else{
    			prev = tmp;
    			tmp = tmp->next;
    		}
    	}
        return head;
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
	next = new ListNode(6);
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

	Solution s;
	ListNode *nfirst = s.removeElements(first,6);

	tmp = nfirst;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}

	cout<<endl;


	return 0;
}