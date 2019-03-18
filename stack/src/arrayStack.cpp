#include "arrayStack.h"
#include <iostream>
using namespace std;

void arrayStack::doubleLength()
{
    arrayLength *=2;
    int *stack1 = new int[arrayLength];
    std::copy(stack, stack + stackTop, stack1);
    delete []stack;
    stack = stack1;
}

arrayStack::arrayStack(int initialCapacity)
{
    stack = new int[initialCapacity];
    arrayLength = initialCapacity;
    stackTop = -1;
}

arrayStack::~arrayStack()
{
    delete []stack;
    arrayLength = 0;
    stackTop = -1;
}

int& arrayStack::top() const
{
	return stack[stackTop];
}

void arrayStack::pop()
{
    stack[stackTop] = 0;
    stackTop--;
}

void arrayStack::push(const int& theElement)
{
    if(stackTop == arrayLength)
        doubleLength();
    stack[++stackTop] = theElement;
}
