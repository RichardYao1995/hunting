#include "chain.h"
#include <iostream>
using namespace std;

chain::chain(int initialCapacity)
{
    firstNode = NULL;
    listSize = initialCapacity;
}

chain::chain(const chain& theList)
{
    listSize = theList.listSize;
    chainNode *sourceNode = theList.firstNode;
    firstNode = new chainNode(sourceNode->element);

    sourceNode = sourceNode->next;
    chainNode *targetNode = firstNode;

    while(sourceNode != NULL)
    {
        targetNode = new chainNode(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode = NULL;
}

chain::~chain()
{
    chainNode *nextNode = firstNode;
    while(nextNode != NULL)
    {
        chainNode *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

int& chain::get(int theIndex) const
{
	if(theIndex >= listSize)
		throw "out of range!";
    chainNode *nextNode = firstNode;
    for(int i = 0;i < theIndex;i++)\
        nextNode = nextNode->next;
    return nextNode->element;
}

int chain::indexOf(const int& theElement) const
{
    chainNode *nextNode = firstNode;
    int m = 0;
    while(nextNode != NULL)
    {
        if(nextNode->element == theElement)
            return m;
        nextNode = nextNode->next;
        m++;
    }
	return -1;
}

void chain::erase(int theIndex)
{
    chainNode *nextNode = firstNode;
	if(theIndex >= listSize)
		throw "out of range!";
    if(theIndex == 0)
        firstNode = firstNode->next;
    else
    {
        for(int num = 0;num < theIndex - 1;num++)
            nextNode = nextNode->next;
        chainNode *deleteNode = nextNode->next;
        nextNode->next = nextNode->next->next;
        delete deleteNode;
    }
    listSize--;
}

void chain::insert(int theIndex, const int& theElement)
{
    if(theIndex == 0)
    {
        chainNode *addNode = new chainNode(theElement);
        addNode->next = firstNode;
        firstNode = addNode;
        return;
    }
    chainNode *nextNode = firstNode;
    for(int num = 0;num < theIndex - 1;num++)
        nextNode = nextNode->next;
    nextNode->next = new chainNode(theElement,nextNode->next);
    listSize++;
}
