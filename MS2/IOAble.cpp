/* Citation and Sources...
General Hospital Pre-Triage Application
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	CJ Jingren Tong
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/08  Milestone 1 Completion (Time & Utils Module)
2021/03/09  Update getcstr function without using string class
2021/03/18  Milestone 2 Completion
2021/03/19  Walk through IOAble tester
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"
using namespace std; 
namespace sdds {
	ostream& operator<<(ostream& ostr, const IOAble& ro)
	{
		return ro.write(ostr); 
	}

	std::istream& operator>>(std::istream& istr, IOAble& ro)
	{
		return ro.read(istr); 
	}

}
