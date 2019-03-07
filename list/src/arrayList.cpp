#include "arrayList.h"
#include <iostream>
using namespace std;

//template<class T>
void arrayList::doubleLength()
{
    arrayLength *= 2;
    int* element1 = new int[arrayLength];
    std::copy(element, element + listSize, element1);
    delete []element;
    element = element1;
}

//template<class T>
void arrayList::halfLength()
{
    arrayLength /= 2;
    int* element1 = new int[arrayLength];
    std::copy(element, element + listSize, element1);
    delete []element;
    element = element1;
}

//template<class T>
arrayList::arrayList(int initialCapacity)
{
    element = new int[initialCapacity];
	arrayLength = initialCapacity;
	listSize = 0;
}

//template<class T>
arrayList::arrayList(const arrayList& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
    element = new int[arrayLength];
	std::copy(theList.element, theList.element + listSize, element);
}

//template<class T>
int& arrayList::get(int theIndex) const
{
	if(theIndex >= listSize)
		throw "out of range!";
	return element[theIndex];
}

//template<class T>
int arrayList::indexOf(const int& theElement) const
{
	for(int num = 0;num < listSize;num++)
	{
		if(theElement == element[num])
			return num;
	}
	return -1;
}

//template<class T>
void arrayList::erase(int theIndex)
{
	if(theIndex >= listSize)
		throw "out of range!";
	for(int num = theIndex;num < listSize - 1;num++)
		element[num] = element[num+1];
	if(listSize * 4 < arrayLength)
		halfLength();
}

//template<class T>
void arrayList::insert(int theIndex, const int& theElement)
{
	if(arrayLength == listSize)
		doubleLength();
	for(int num = listSize;num > theIndex;num--)
		element[num] = element[num - 1];
	element[theIndex] = theElement;
	listSize++;                      //forget
}
