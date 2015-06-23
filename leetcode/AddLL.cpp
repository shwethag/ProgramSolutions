#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        int carry = 0;
        ListNode *c1 = A,*c2 = B,*sum,*cur,*prev=NULL;
        int d1,d2,s;
        while(c1 || c2){
        	d1 = (c1)?c1->val:0;
        	d2 = (c2)?c2->val:0;
        	s = d1 + d2 + carry;
        	if(s>9){
        		carry = s/10;
        		s = s%10;
        	}else
        		carry = 0;
        	cur = new ListNode(s);
        	if(prev){
        		prev->next = cur;
        		prev = cur;
        	}else{
        		sum = cur;
        		prev = cur;
        	}
        	if(c1) c1 = c1->next;
        	if(c2) c2 = c2->next;
        }

        if(carry)
        {
        	cur = new ListNode(carry);
        	prev->next = cur;
        }


        return sum;
    }
};

int main(){
	ListNode *num1 = new ListNode(9);
	num1->next = new ListNode(9);
	//num1->next->next = new ListNode(3);

	ListNode *num2 = new ListNode(1); //564
	//num2->next = new ListNode(6);
	//num2->next->next = new ListNode(4);

	Solution s;
	ListNode *sum = s.addTwoNumbers(num1,num2);

	ListNode *cur = sum;
	while(cur!=NULL){
		cout<<cur->val;
		cur = cur->next;
	}
	cout<<endl;



	return 0;
}