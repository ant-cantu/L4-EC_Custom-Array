//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : L4-3	(myArray.h)			                        * 
//*                                                                     * 
//* Written by      : Anthony Cantu                                     * 
//*                                                                     * 
//* Purpose         : Header file containing the class myArray along	*
//*					  with its member functions and variables.			*
//*                                                                     * 
//* Inputs          : No Inputs											*
//*                                                                     * 
//* Outputs         : No Outputs										*
//*                                                                     * 
//* Calls           :													*
//*					friend:												*
//*						operator<< (ostream&, const myArray<T>&);		*
//*																		*
//*					public:												*
//*						operator[] (int index);							*
//*						operator[] (int index) const;					*
//*						operator= (const myArray<arrayType>&);			*
//*																		*
//*					constructor:										*
//*						myArray(int);									*
//*						myArray(int, int);								*
//*																		*
//*					destructor:											*
//*						~myArray();										*
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Collaboration   : The Goonies										*
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 12/04/23      acantu 000.000.000 Initial release of program       	* 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#pragma once

#include <ostream>

template <class arrayType>
class myArray
{
	template <class T>
	friend std::ostream& operator<< (std::ostream&, const myArray<T>& cObject);
	//<< insertion overload operator
	//Overload operator for myArray class. 
	//Called when an array created within
	//myArray is used with an insertion operator.

public:
	arrayType& operator[] (int index);
	//non-constant
	//[] array overload operator
	//Overload operator for myArray class.
	//Called when myArray is defined as
	//an array.

	const arrayType& operator[] (int index) const;
	//constant
	//[] array overload operator
	//Overload operator for myArray class.
	//Called when myArray is defined as
	//an array.

	const myArray<arrayType>& operator= (const myArray<arrayType>& otherArray);
	//= assignment overload operator
	//Overload operator for myArray class.
	//Called when myArray is included in
	//an assignment.

	myArray(int size);
	//Default constructor
	//Creates a new array with the size provided
	//by the parameters.
	//Precondtion: No preconditions.
	//Postcondition: newArray[size] created.
	//				 minSize = 0;
	//				 maxSize = size;
	//				 newArray[size] = 0;

	myArray(int min, int max);
	//Default constructor
	//Creates a new array with the size provided
	//by the parameters. Allows for negative index.
	//Precondtion: No preconditions.
	//Postcondition: newArray[size] created.
	//				 minSize = min;
	//				 maxSize = max;
	//				 newArray[size] = 0;

	~myArray();
	//Destructor
	//Releases myArray.
	//Postcondition: myArray = nullptr;

private:
	arrayType* newArray;	//arrayType pointer which stores a new array created.
	int maxSize;			//Integer value to store the max size of the array.
	int minSize;			//Integer value to store the minium size of the array.
};

//myArray.cpp, the implementation file.
#include "myArray.cpp"