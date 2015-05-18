#include <iostream>

using namespace std;
/*
Sort a linked list in O(n log n) time using constant space complexity.
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

	void split(ListNode **head, ListNode **part1, ListNode **part2){
    	ListNode *slow, *fast;
    	slow = *head;
    	fast = (*head)->next;
    	while(fast!=NULL){
    		fast = fast->next;
    		if(fast!=NULL){
    			fast = fast->next;
    			slow = slow->next;
    		}	
    	}
    	*part1 = *head;
    	*part2 = slow->next;
    	slow->next = NULL;
    }

    ListNode* merge(ListNode *part1, ListNode *part2){
    	if(part1 == NULL)
    		return part2;
    	if(part2 == NULL)
    		return part1;
    	ListNode *nFirst = NULL,*cur = nFirst;
    	while(part1!=NULL && part2 != NULL){
    	
    		if(part1->val < part2->val){
    			if(cur == NULL){
    				nFirst = part1;
    				cur = nFirst;
    			}
    			else{
    				cur->next = part1;
    				cur = cur->next;
    			}

    			part1 = part1->next;
    		}else{
    			if(cur == NULL){
    				nFirst = part2;
    				cur = nFirst;
    			}
    			else{
    				cur->next = part2;
    				cur = cur->next;
    			}

    			part2 = part2->next;
    		}
    		
    	}
    	if(part1!=NULL)
    		cur->next = part1;
    	if(part2!=NULL)
    		cur->next = part2;

    	return nFirst;
    }


    ListNode* sortList(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode *part1 = NULL,*part2 = NULL;
    	split(&head,&part1,&part2);
        part1 = sortList(part1);
       
        part2 = sortList(part2);


        head = merge(part1,part2);
       
        return head;
    }



};

int main(){
	Solution s;
	ListNode *first=NULL;
	ListNode *next,*tmp;
	first = new ListNode(4);

	
	next = new ListNode(3);
	tmp = first;
	tmp->next = next;

	tmp = next;
	next = new ListNode(1);
	tmp->next = next;

	tmp = next;
	next = new ListNode(5);
	tmp->next = next;

	tmp = next;
	next = new ListNode(6);
	tmp->next = next;

	tmp = next;
	next = new ListNode(2);
	tmp->next = next;

	first = s.sortList(first);

	tmp = first;

	while(tmp!=NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;


	
	return 0;
}