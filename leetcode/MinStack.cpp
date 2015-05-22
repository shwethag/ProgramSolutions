#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/


class MinStack {
	int *stack;
	int capacity;
	int sTop;
	int curmin;

public:
	MinStack(){
		sTop = -1;
		capacity = 1;
		stack = (int *)malloc(sizeof(int));
		curmin = INT_MAX;
	}

	void storeMin(){
		//cout<<"storing new min "<<endl;
		int ttop = -1;
		int *tempStack = (int *)malloc(sizeof(int)*capacity);
		int cur;
		curmin = INT_MAX;
		while((cur = top())!=INT_MAX){
			tempStack[++ttop] = cur;
			if(cur < curmin)
				curmin = cur;
			sTop--;
		}

		while(ttop != -1){
			stack[++sTop] = tempStack[ttop--];
		}

		free(tempStack);
	}


    void push(int x) {
        if(sTop >= capacity-1){
        	capacity = capacity*2;
        	int *newLoc = (int *)realloc(stack,capacity*sizeof(int));
        	if(newLoc == NULL)
        	{
        		return;
        	}
        	stack = newLoc;
        }
        stack[++sTop] = x;
        if(x < curmin)
        	curmin = x;
    }

    void pop() {
    	if(sTop == -1)
    		return;
    	bool refindMin = false;
    	if(top()==curmin){
    		refindMin = true;
    	}
        sTop--;
        if(sTop == -1)
        {
        	curmin = INT_MAX;
        	return;
        }
        if(2*sTop < capacity){
        	capacity = capacity/2;
        	stack = (int *)realloc(stack,capacity*sizeof(int));
        }
        if(refindMin){
        	storeMin();
        }
    }

    int top() {

    	if(sTop == -1)
    		return INT_MAX;

        return stack[sTop];
    }

    int getMin() {
        return curmin;
    }
};


int main(){
	MinStack ms;

	ms.push(85);
	ms.push(-99);
	ms.push(67);
	cout<<ms.getMin()<<endl;
	ms.push(-27);
	ms.push(61);
	ms.push(-97);
	ms.push(-27);
	ms.push(35);
	cout<<ms.top()<<endl;
	ms.push(99);
	ms.push(-66);
	cout<<ms.getMin()<<endl;
	ms.push(-89);
	cout<<ms.getMin()<<endl;
	ms.push(4);
	ms.push(-70);
	cout<<ms.getMin()<<endl;
	ms.push(52);
	cout<<ms.top()<<endl;
	ms.push(54);
	cout<<ms.getMin()<<endl;
	ms.push(94);
	ms.push(-41);
	ms.push(-75);
	ms.push(-32);
	cout<<ms.getMin()<<endl;
	ms.push(5);
	ms.push(29);
	cout<<ms.top()<<endl;
	ms.push(-78);
	ms.push(-74);
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.push(-58);
	ms.push(-44);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.push(-64);
	cout<<ms.getMin()<<endl;
	ms.pop();
	ms.push(-45);
	ms.push(-99);
	ms.push(-27);
	cout<<ms.getMin()<<endl;
	ms.push(-96);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.push(26);
	ms.push(-58);
	cout<<ms.getMin()<<endl;
	cout<<ms.top()<<endl;
	cout<<ms.getMin()<<endl;
	ms.push(25);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.push(33);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.push(71);
	cout<<ms.getMin()<<endl;
	ms.push(-62);
	cout<<ms.getMin()<<endl;
	ms.push(-78);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.push(-30);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;
	ms.push(85);
	ms.push(-15);
	ms.pop();
	ms.push(-40);
	cout<<ms.getMin()<<endl;
	ms.push(72);
	cout<<ms.top()<<endl;
	cout<<ms.top()<<endl;
	ms.push(18);
	ms.push(59);
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.push(-59);
	cout<<ms.top()<<endl;
	ms.push(10);
	cout<<ms.getMin()<<endl;
	ms.push(9);
	cout<<ms.getMin()<<endl;
	cout<<ms.getMin()<<endl;


	return 0;
}