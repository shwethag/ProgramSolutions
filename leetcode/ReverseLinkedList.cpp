#include <iostream>

using namespace std;

/*Reverse a singly linked list.
1->2->3->4->5->6
p  c  n
1<-2  3->4
   p  c  n  
*/

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp = NULL,*next = NULL;
        while(head){
        	next = head->next;
        	head->next = tmp;
        	tmp = head;
        	head = next;

        }
        return tmp;
    }
};

int main(){
	Solution s;
	ListNode *first=NULL;
	first = new ListNode(1);

	ListNode *next,*tmp;
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

	

	first = s.reverseList(first);

	tmp = first;
	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;

	return 0;
}