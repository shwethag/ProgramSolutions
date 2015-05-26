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
	int *min_stack;
	int mTop;
	int mCapacity;
	int capacity;
	int sTop;

public:
	MinStack(){
		sTop = -1;
		mTop = -1;
		mCapacity = 1;
		capacity = 1;
		stack = (int *)malloc(sizeof(int));
		min_stack = (int *)malloc(sizeof(int));
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
        if(mTop == -1 || x <= min_stack[mTop]){
        	minPush(x);
        }
    }

    void minPush(int x){
    	 if(mTop >= mCapacity-1){
        	mCapacity = mCapacity*2;
        	int *newLoc = (int *)realloc(min_stack,mCapacity*sizeof(int));
        	if(newLoc == NULL)
        	{
        		return;
        	}
        	min_stack = newLoc;
        }
        min_stack[++mTop] = x;
    }

    void popMin(){
    	if(mTop == -1)
    		return;
        mTop--;
        
        if(2*mTop < mCapacity){
        	mCapacity = mCapacity/2;
        	if(mCapacity == 0)
        		mCapacity = 1;
        	min_stack = (int *)realloc(min_stack,mCapacity*sizeof(int));
        }
    }

    void pop() {
    	if(sTop == -1)
    		return;
    	if(top()==min_stack[mTop]){
    		popMin();
    	}
        sTop--;
        if(2*sTop < capacity){
        	capacity = capacity/2;
        	if(capacity == 0)
        		capacity = 1;
        	stack = (int *)realloc(stack,capacity*sizeof(int));
        }
        
    }

    int top() {

    	if(sTop == -1)
    		return INT_MAX;

        return stack[sTop];
    }

    int getMin() {
    	if(mTop == -1)
    		return INT_MAX;
        return min_stack[mTop];
    }
};


int main(){
	MinStack ms;

	ms.push(2147483646);
	ms.push(2147483646);
	ms.push(2147483647);
	cout<<ms.top()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.pop();
	ms.push(2147483647);
	cout<<ms.top()<<endl;
	cout<<ms.getMin()<<endl;
	cout<<"pushing "<< -2147483648<<endl;
	ms.push(-2147483648);
	cout<<ms.top()<<endl;
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	return 0;
}