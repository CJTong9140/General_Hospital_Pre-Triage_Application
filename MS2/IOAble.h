/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.h
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
