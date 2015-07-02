#include <iostream>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */ 
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        RandomListNode *nhead = new RandomListNode(head->label);
        map<RandomListNode *,RandomListNode *> nodemap;
        nodemap[head] = nhead; 
        RandomListNode *cur = head->next;
        RandomListNode *ncur = nhead,*node;
        while(cur){
            node = new RandomListNode(cur->label);
            ncur->next = node;
            ncur =  ncur->next;
            nodemap[cur] = ncur;
            cur = cur->next;
        }
        
        cur = head;
        RandomListNode *ran;
        while(cur){
            ran = cur->random;
            nodemap[cur]->random = nodemap[ran];
            
            cur = cur->next;
            
        }
        return nhead;
    }
};

int main(){
	
	return 0;
}