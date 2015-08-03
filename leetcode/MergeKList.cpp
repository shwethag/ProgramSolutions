#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct Compare{
    bool operator() (ListNode* &a,ListNode* &b){
        return a->val > b->val;
    }
};
 
 
class Solution {
public:
	

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<ListNode *,vector<ListNode *>,Compare> pq;
    	for(int i=0;i<lists.size();i++){
    		if(lists[i])
    			pq.push(lists[i]);
    	}
    	ListNode *head = new ListNode(0);
    	ListNode *cur = head;
    	while(!pq.empty()){
    		ListNode *top = pq.top();
    		pq.pop();
    		cur->next = top;
    		cur = cur->next;
    		if(top->next)
    			pq.push(top->next);
    	}

    	cur = head;
    	head = head->next;
    	delete cur;
    	return head;

        
    }
};

int main(){

	vector<ListNode *> lists;
	ListNode *l1 = new ListNode(3);
	l1->next = new ListNode(6);
	l1->next->next = new ListNode(10);

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(5);
	l2->next->next = new ListNode(13);

	lists.push_back(l1);
	lists.push_back(l2);

	Solution s;

	ListNode * nlist = s.mergeKLists(lists);

	ListNode *cur = nlist;
	while(cur){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;
	
	return 0;
}