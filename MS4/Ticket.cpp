/* Citation and Sources...
General Hospital Pre-Triage Application
Module: Ticket (Derived class from IOAble)
Filename: Ticket.cpp
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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Ticket.h"
namespace sdds {
   Ticket::Ticket(int number) {
      m_number = number;
   }

   // when it is cast to Time it will return the m_time
   Ticket::operator Time() const {
      return m_time;
   }

   // return the number of the ticket
   int Ticket::number() const {
      return m_number;
   }

   // set the ticket time to the current time. 
   void Ticket::resetTime() {
      m_time.setToNow();
   }

   // output comma-separated ticket number and time (insert to ostream)
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
      return ostr << m_number << "," << m_time;
   }

   // extract the ticket number and time from input stream
   std::istream& Ticket::csvRead(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      return istr >> m_time;
   }

   // insert a ticket into the ostream to be displayed on console
   std::ostream& Ticket::write(std::ostream& ostr) const {
      return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time ;
   }

   // extract the ticket information from istream. 
   std::istream& Ticket::read(std::istream& istr) {
      return csvRead(istr);
   }
}
