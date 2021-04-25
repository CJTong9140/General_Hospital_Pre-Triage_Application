/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author	CJ Jingren Tong
Revision History
-----------------------------------------------------------
Date        Reason
2021/03/08  Milestone 1 Completion (Time & Utils Module)
2021/03/09  Update getcstr function without using string class
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