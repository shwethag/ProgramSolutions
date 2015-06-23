#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        while(fast!=NULL){
            if(fast->next && fast->next->next)
                fast = fast->next->next;
            else
                fast = NULL;
            
            slow = slow->next;
            if(fast!= NULL && fast == slow)
                break;
        }
        if(fast == NULL)
        	return NULL;

        fast = head;
        while(fast!=slow){
        	fast = fast->next;
        	slow = slow->next;
        }
       return slow;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	ListNode *cyc = head->next->next;

	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = cyc;


	Solution s;
	ListNode *c = s.detectCycle(head);
	c?cout<<c->val<<endl:cout<<"NULL"<<endl;


	return 0;
}