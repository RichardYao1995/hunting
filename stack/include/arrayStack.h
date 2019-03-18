#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H
#include "stack.h"

class arrayStack: public stack<int>
{
	public:
        arrayStack(int initialCapacity = 10);
        ~arrayStack();

        bool empty() const {return stackTop == -1;}
        int size() const {return stackTop + 1;}
        int& top() const;
        void pop();
        void push(const int& theElement);

    protected:
        int stackTop;
        int arrayLength;
        int *stack;
        void doubleLength();
};

#endif
