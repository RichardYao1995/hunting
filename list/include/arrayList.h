#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#include "linearList.h"
using namespace std;

//template<class T>
class arrayList: public linearList<int>
{
	public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList&);
        ~arrayList(){delete []element;}

        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        int& get(int theIndex) const;
        int indexOf(const int& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const int& theElement);
        int capacity() const {return arrayLength;}

    protected:
        int* element;
        int arrayLength;
        int listSize;
        void doubleLength();
        void halfLength();
};

#endif
