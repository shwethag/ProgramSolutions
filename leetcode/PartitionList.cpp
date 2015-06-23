#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool compare(ListNode *n1,ListNode *n2){
		return n1->val < n2->val;
	}

    ListNode* partition(ListNode* head, int x) {
    	if(!head || !head->next)
    		return head;
        ListNode *less = NULL,*il = less, *more = NULL,*im = more;

        ListNode *cur = head;
        while(head != NULL){
        	cur = head;
        	head = head->next;

        	if(cur->val < x)
        	{
        		if(il)
				{
					il->next = cur;
					il = il->next;
				}else{
					il = cur;
					less = cur;
				}        			
        	}else{
        		if(im){
        			im->next = cur;
        			im = im->next;
        		}else{
        			im = cur;
        			more = cur;
        		}
        	}

        }

       	if(il) il->next = more;
       	if(im) im->next = NULL;
       	if(less)
       		return less;
       	return more;
    }
};

int main(){
	//1->4->3->2->5->2 and x = 3,  1->2->2->4->3->5. 
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(1);
	cur = cur->next;

	/*cur->next = new ListNode(3);
	cur = cur->next;

	cur->next = new ListNode(2);
	cur = cur->next;

	cur->next = new ListNode(5);
	cur = cur->next;

	cur->next = new ListNode(1);
*/
	Solution s;
	head = s.partition(head,3);

	cur  = head;
	while(cur!=NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;
	return 0;
}