#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode* hasK(ListNode *node,int k){
		ListNode *cur = node,*prev = NULL;
		while(k && cur){
			prev = cur;
			cur = cur->next;
			k--;
		}
		if(k)
			return NULL;
		return prev;
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 0 || k == 1)
        	return head;
        ListNode *cur = head,*tmp = NULL,*last=NULL,*nxt,*prev = NULL,*node;
        int n = 0;
        bool ishead = true;
        while((node = hasK(cur,k))){
        	n = 0;
        	last = cur;
        	while(n<k){ // 1->2->3  ==  <-1<-2 3>4>5>6  == <1<2  <3<4  2 1 4 3 6 5
        		nxt = cur->next;
        		cur->next = prev;
        		prev = cur;
        		cur = nxt;
        		n++;
        	}

        	if(ishead){
        		tmp = head;
        		head = prev;
        		
        	}else{
        		tmp->next = node;
        		tmp = last;
        	}
        	
        	ishead = false;
        }

        if(last)
        	last->next = cur;

        return head;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(2);
	cur = cur->next;

	cur->next = new ListNode(3);
	cur = cur->next;

	cur->next = new ListNode(4);
	cur = cur->next;

	cur->next = new ListNode(5);
	cur = cur->next;

	cur->next = new ListNode(6);

	cur  = head;
	while(cur!=NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;

	Solution s;

	head = s.reverseKGroup(head,8);

	cur  = head;
	while(cur!=NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;

	return 0;
}