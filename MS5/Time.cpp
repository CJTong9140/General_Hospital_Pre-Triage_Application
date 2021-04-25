/* Citation and Sources...
Final Project Milestone
Module: Time
Filename: Time.cpp
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
2021/03/27	Milestone 4 (CovidPatient and TriagePatient module implementation)
			Unit testing each modules, and walked through ms4Tester.
2021/03/29	Added function template removeDynamicElement into the utils.h file.
			Completed PreTriage constuctor, destructor, load(), making sure data filename being set dynamically and safely. Also made sure
			Patient records are imported from the data file correctly by using the load().
			Making sure data file is able to overwrite/write to the datafile correctly, and being allocated memory being deallocated safely
			by using the destructor.
2021/03/30	Implemented reg(), getWaitTime() function, used unit testing method to test the functions
2021/03/30	Implemented admit(), indexOfFirstInLine(), removePatientFromLineup() and setAverageWaitTime(), used unit testing method to test
			the functions
2021/04/01	Implemented run(), used fp1Tester to test with new(non-existent) data file
2021/04/02	Used fp2Tester to test small data file, fp3Tester to test big data file. And fpTester that is combined with all three testers.
			Edited some line breaks and output formats.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = getTime(); 
		return *this; 
	}

	Time::Time(unsigned int min): m_min(min)
	{
	}

	ostream& Time::write(ostream& ostr) const
	{
		ostr << setw(2) << setfill('0') << int(m_min / 60) << ":"
			<< setw(2) << m_min % 60; 

		return ostr; 
	}

	istream& Time::read(istream& istr)
	{
		int hour = 0;
		int minute = 0; 
		char c = '\0';
		istr >> hour; 
		istr >> c; 
		istr >> minute; 
		if(hour < 0 || c != ':' || minute < 0)
			istr.setstate(ios::failbit);
		m_min = hour * 60 + minute; 
		return istr; 
	}

	Time& Time::operator-=(const Time& D)
	{
		int hour = 24; 
		int minutes = 60; 
		while(m_min < D.m_min) {
			m_min += (hour * minutes);
		}
		m_min -= D.m_min; 
		return *this; 
	}

	Time Time::operator-(const Time& D) const
	{
		unsigned time = m_min; 
		int hour = 24;
		int minutes = 60;
		while (time < D.m_min) {
			time += (hour * minutes);
		}
		return Time(time - D.m_min);
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min; 
		return *this; 
	}

	Time Time::operator+(const Time& D) const
	{
		return Time(m_min + D.m_min);
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val; 
		return *this; 
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val; 
		return *this; 
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val; 
		return *this; 
	}

	Time Time::operator*(unsigned int val) const
	{
		return Time(m_min * val);
	}

	Time Time::operator/(unsigned int val) const
	{
		return Time(m_min / val);
	}

	Time::operator unsigned int() const
	{
		return m_min; 
	}

	Time::operator int() const
	{
		return (int)m_min; 
	}

	ostream& operator<<(ostream& ostr, const Time& D)
	{
		return D.write(ostr); 
	}

	istream& operator>>(istream& istr, Time& D)
	{
		return D.read(istr); 
	}

}