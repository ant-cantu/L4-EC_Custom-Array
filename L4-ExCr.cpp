//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : L4-3	(Test Program)		                        * 
//*                                                                     * 
//* Written by      : Anthony Cantu                                     * 
//*                                                                     * 
//* Purpose         : Test program to test the headers:                 * 
//*						myArray.h										*
//*                                                                     * 
//* Inputs          : User inputs integers for the prompts				*
//*                                                                     * 
//* Outputs         : Outputs the arrays created and their values.		*
//*                                                                     * 
//* Calls           : myArray::operator[]								*
//*					  myArray::operator=								*
//*					  myArray::operator<<								*
//*					  myArray::myArray()		 						*
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
#include <iostream>
#include <iomanip>
#include "myArray.h"

using namespace std;

int main()
{
	cout << "Anthony Cantu" << "\tL4-5" << "L4-5.exe" << endl;

	cout << endl; //Line Break

	cout << "Creating: myArray list1(5)";
	myArray<int> list1(5);

	cout << endl; //Line Break
		
	cout << "Creating: myArray list2(5)";
	myArray<int> list2(5);

	cout << endl; //Line Break

	cout << "Output list1: cout << \"list1 : \" << list 1 << endl;" << endl;
	cout << "list1 : " << list1;

	cout << endl << endl; //Line Break;

	cout << "Enter 5 integers for list1: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> list1[i];
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry type for integer #" << i + 1 <<". Please try again: ";
			i--;
		}
	}

	cout << endl;	//Line Break

	cout << "After filling list1: " << list1;

	cout << endl << endl;	//Line Break

	cout << "set list2 equal to list1: list2 = list1" << endl;
	list2 = list1;
	cout << "Output list2: cout << \"list2 : \" << list2 << endl;" << endl;
	cout << "list2 : " << list2 << endl;

	cout << endl;	//Line Break

	cout << "Enter 3 elements for list1: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> list1[i];
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry type for integer #" << i + 1 << ". Please try again: ";
			i--;
		}
	}

	cout << endl;	//Line Break

	cout << "First three elements of list1: ";
	for (int i = 0; i < 3; i++)
		cout << list1[i] << " ";

	cout << endl;	//Line Break
	
	cout << "Creating: myArray list3(-2, 6)" << endl;
	myArray<int> list3(-2, 6);
	cout << "Output list3: cout << \"list3 : \" << list3 << endl;" << endl;

	cout << "list3: " << list3 << endl;

	cout << endl;	//Line Break

	cout << "Set elements for list3:  list3[-2] = 7" << endl;
	cout << setw(38) << right << "list3[4] = 8" << endl;
	cout << setw(39) << right << "list3[0] = 54" << endl;
	cout << setw(26) << right << " ";
	cout << "list3[2] = list3[4] + list3[-2]" << endl;

	list3[-2] = 7;
	list3[4] = 8;
	list3[0] = 54;
	list3[2] = list3[4] + list3[-2];

	cout << "Output list3: cout << \"list3 : \" << list3 << endl;" << endl;
	cout << "list3 : " << list3 << endl;

	cout << endl;	//Line Break

	char q;
	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}