/* Citation and Sources...
Final Project Milestone 
Module: IOAble Interface
Filename: IOAble.h
Version 1.0
Author	CJ Jingren Tong
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/08  Milestone 1 Completion (Time & Utils Module)
2021/03/09  Update getcstr function without using string class
2021/03/18  Milestone 2 Completion (Menu Module & IOAble interface module)
2021/03/19  Walk through IOAble tester
2021/03/23  Milestone 3 (Patient Module implementation -- abstract IOAble patient class)
2021/03/23  Error checking with Patient tester that I have created. Modified condition inside of the getcstr function within utils module
2021/03/24  Error checking with FileIO tester that I have created. Modified csvRead() method inside of the Patient module.
			Because the file we are reading from contains the 6th line, or any files we would need to read from contains a
			blank line at the end. We should stop reading the line if there is nothing within the line.
2021/03/24  Walked through Milestone 3 with ms3Tester.cpp
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_IOABLE_H__
#define SDDS_IOABLE_H__
#include <iostream>
namespace sdds {
	class IOAble {
	public: 
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0; 
		virtual std::istream& csvRead(std::istream& istr) = 0; 
		virtual std::ostream& write(std::ostream& ostr) const = 0; 
		virtual std::istream& read(std::istream& istr) = 0; 
		virtual ~IOAble() {};
	};
	std::ostream& operator << (std::ostream& ostr, const IOAble& rightOperand); 
	std::istream& operator >> (std::istream& istr, IOAble& rightOperand); 
}
#endif
