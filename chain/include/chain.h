#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#include "linearList.h"
using namespace std;

struct chainNode
{
    int element;
    chainNode *next;

    chainNode() {}
    chainNode(const int &element)
    {
        this->element = element;
    }
    chainNode(const int &element, chainNode* next)
    {
        this->element = element;
        this->next = next;
    }
};

class chain: public linearList<int>
{
	public:
        chain(int initialCapacity = 10);
        chain(const chain&);
        ~chain();

        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        int& get(int theIndex) const;
        int indexOf(const int& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const int& theElement);

    protected:
        chainNode *firstNode;
        int listSize;
};

#endif
