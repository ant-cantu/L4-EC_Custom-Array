#pragma once

#include "myArray.h"
#include <cmath>
#include <iostream>
#include <assert.h>

using namespace std;

//Overload operators
template <class arrayType>
ostream& operator<< (ostream& osObject, const myArray<arrayType>& cObject)
{
	for (int i = cObject.minSize; i < cObject.maxSize; i++)
		osObject << cObject.newArray[i] << " ";

	return osObject;
}

//Class member overload operations
template <class arrayType>
arrayType& myArray<arrayType>::operator[] (int index)
{
	assert(minSize <= index && index < maxSize);
	return newArray[index];
}

template <class arrayType>
const arrayType& myArray<arrayType>::operator[] (int index) const
{
	assert(minSize <= index && index < maxSize);
	return newArray[index];
}

template <class arrayType>
const myArray<arrayType>& myArray<arrayType>::operator=(const myArray<arrayType>& otherArray)
{
	if (this != &otherArray)
	{
		delete[] newArray;
		maxSize = otherArray.maxSize;
		minSize = otherArray.minSize;

		newArray = new arrayType[maxSize];

		//If negative starting point
		if (minSize < 0)
			newArray = &newArray[abs(minSize)];

		for (int i = minSize; i < maxSize; i++)
			newArray[i] = otherArray.newArray[i];
	}
	return *this;
}

//Constructors
template <class arrayType>
myArray<arrayType>::myArray(int size)
{
	maxSize = size;
	minSize = 0;
	newArray = new arrayType[maxSize];

	for (int i = minSize; i < maxSize; i++)
		newArray[i] = 0;
}

template <class arrayType>
myArray<arrayType>::myArray(int min, int max)
{
	minSize = min;
	maxSize = max;

	newArray = new arrayType[maxSize + abs(min)]; 
	//Set array size
	//min = -2, max = 6
	//2 + 6 = 8;
	//8 elements

	newArray = &newArray[abs(min)];
	//Set starting point of array
	//If min = -2, set starting point to 2
	//max = 6
	// 1  2  3  4  5  6  7  8
	// 0  1  2  3  4  5  6  7 (off by 1)
	//-2 -1  0  1  2  3  4  5 (off by 1)
	//newArray[-2] should = newArray[0]

	for (int i = minSize; i < maxSize; i++)
		newArray[i] = 0;
}

template <class arrayType>
myArray<arrayType>::~myArray()
{
	//I can't figure this part out.
	//Error is thrown when delete[] newArray; is called
	
	//delete[] newArray;
	//newArray = nullptr;
}