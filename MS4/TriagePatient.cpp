/* Citation and Sources...
Final Project Milestone
Module: TriagePatient (Concrete class, derived class from Patient)
Filename: TriagePatient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std; 
namespace sdds {
   int nextTriageTicket = 1;

   void TriagePatient::setSymptoms(const char* symptom)
   {
	   deallocate(); 
	   if (symptom) {
		   m_symptoms = new char[strlen(symptom) + 1]; 
		   strcpy(m_symptoms, symptom); 
		   delete[] symptom; 
	   }
   }

   void TriagePatient::deallocate()
   {
	   delete[] m_symptoms; 
	   m_symptoms = nullptr; 
   }

   TriagePatient::TriagePatient() : Patient(nextTriageTicket++) {}

   char TriagePatient::type() const
   {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& ostr) const
   {
	   Patient::csvWrite(ostr); 
	   ostr << ',' << m_symptoms; 
	   return ostr; 
   }

   istream& TriagePatient::csvRead(istream& istr)
   {
	   Patient::csvRead(istr); 
	   istr.ignore();
	   setSymptoms(getcstr(nullptr, istr, '\n')); 
	   nextTriageTicket = number() + 1; 
	   return istr; 
   }

   ostream& TriagePatient::write(ostream& ostr) const
   {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "TRIAGE" << endl; 
		   Patient::write(ostr) << endl << "Symptoms: " << m_symptoms << endl; 
	   }
	   return ostr; 
   }

   istream& TriagePatient::read(istream& istr)
   {
	   if (fileIO()) {
		   csvRead(istr); 
	   }
	   else {
		   Patient::read(istr); 
		   setSymptoms(getcstr("Symptoms: ", istr, '\n')); 
	   }
	   return istr; 
   }

   TriagePatient::~TriagePatient()
   {
	   deallocate(); 
   }

}