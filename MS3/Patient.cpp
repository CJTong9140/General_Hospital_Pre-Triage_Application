/* Citation and Sources...
Final Project Milestone
Module: Patient (Abstract class, derived class from IOAble)
Filename: Patient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std; 
namespace sdds {
	Patient& Patient::setName(const char* name)
	{
		deallocate(); 
		if (name) {
			m_pName = new char[strlen(name) + 1]; 
			strcpy(m_pName, name); 
			// because the name was dynamically allocated, deallocate to avoid memory leak
			delete[] name; 
		}
		return *this; 
	}

	void Patient::deallocate()
	{
		delete[] m_pName;
		m_pName = nullptr;
	}

	Patient::Patient(int ticketNo, bool fileFlag) : m_pTicket(ticketNo), m_fileFlag(fileFlag) {}

	Patient::~Patient()
	{
		deallocate(); 
	}

	bool Patient::fileIO() const
	{
		return m_fileFlag;
	}

	Patient& Patient::fileIO(bool fileFlag)
	{
		m_fileFlag = fileFlag; 
		return *this; 
	}

	bool Patient::operator==(const char c) const
	{
		return (type() == c);
	}

	bool Patient::operator==(const Patient& p) const
	{
		return (type() == p.type());
	}

	void Patient::setArrivalTime()
	{
		m_pTicket.resetTime(); 
	}

	Patient::operator Time() const
	{
		return Time(m_pTicket); 
	}

	int Patient::number() const
	{
		return m_pTicket.number();
	}

	ostream& Patient::csvWrite(ostream& ostr) const
	{
		ostr << type() << ',' << m_pName << ',' << m_pOhip << ','; 
		return m_pTicket.csvWrite(ostr); 
	}

	istream& Patient::csvRead(istream& istr)
	{
		setName(getcstr(nullptr, istr, ','));
		if (*m_pName) {
			istr >> m_pOhip;
			istr.ignore();
			m_pTicket.csvRead(istr);
		}
		return istr; 
	}
	
	ostream& Patient::write(ostream& ostr)const
	{
		char* temp = nullptr; 
		int len = strlen(m_pName) > 25 ? 25 : strlen(m_pName);
		temp = new char[len + 1]; 
		strncpy(temp, m_pName, len); 
		temp[len] = char(0); 
		m_pTicket.write(ostr) << endl << temp << ", OHIP: " << m_pOhip;
		delete[] temp; 
		return ostr; 
	}

	istream& Patient::read(std::istream& istr)
	{
		setName(getcstr("Name: ", istr, '\n')); 
		m_pOhip = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ", true);
		return istr;
	}
}