/* Citation and Sources...
General Hospital Pre-Triage Application
Module: PreTriage
Filename: PreTriage.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	void PreTriage::setFilename(const char* fileName)
	{
		deallocate();
		if (fileName) {
			m_dataFilename = new char[strlen(fileName) + 1];
			strcpy(m_dataFilename, fileName);
		}
	}

	void PreTriage::deallocate()
	{
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
	}

	PreTriage::PreTriage(const char* dataFilename)
	{
		setFilename(dataFilename);
		load();
	}

	// open for output, overwriting content in file if already exist
	PreTriage::~PreTriage()
	{
		ofstream fileOut(m_dataFilename);
		if (fileOut) {
			fileOut << m_averCovidWait << ',' << m_averTriageWait << endl;
			cout << "Saving Average Wait Times," << endl
				<< "   COVID Test: " << m_averCovidWait << endl
				<< "   Triage: " << m_averTriageWait << endl
				<< "Saving m_lineup..." << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				m_lineup[i]->fileIO(true);
				fileOut << *m_lineup[i] << endl;;
				cout << i + 1 << "- " << *m_lineup[i] << endl;
				delete m_lineup[i];
			}
			deallocate();
			cout << "done!" << endl;
		}
	}

	void PreTriage::run(void)
	{
		int selection;
		while (m_appMenu >> selection) {
			switch (selection) {
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			default:
				break;
			}
		}
	}

	void PreTriage::reg()
	{
		int selection;
		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			switch (m_pMenu >> selection) {
			case 1:
				m_lineup[m_lineupSize] = new CovidPatient;
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient;
				break;
			default:
				break;
			}
			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->fileIO(false);
			cin >> *m_lineup[m_lineupSize];
			cout << endl << "******************************************" << endl;
			cout << *m_lineup[m_lineupSize];
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;
			m_lineupSize++;
		}
	}

	void PreTriage::admit()
	{
		int selection;
		char type;
		int index;

		switch (m_pMenu >> selection) {
		case 1:
			type = 'C';
			break;
		case 2:
			type = 'T';
			break;
		default:
			break;
		}
		index = indexOfFirstInLine(type); 
		if (index != -1) {
			cout << endl << "******************************************" << endl;
			m_lineup[index]->fileIO(false);
			cout << "Calling for " << *m_lineup[index];
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		Time temp; 
		for (int i = 0; i < m_lineupSize; i++) {
			if (p.type() == m_lineup[i]->type()) {
				temp += (p.type() == 'C') ? m_averCovidWait : m_averTriageWait;
			}
		}
		return temp;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C') {
			m_averCovidWait = ((Time().setToNow() - Time(p)) + (m_averCovidWait * unsigned(p.number() - 1))) / unsigned(p.number());
		}
		else {
			m_averTriageWait = ((Time().setToNow() - Time(p)) + (m_averTriageWait * unsigned(p.number() - 1))) / unsigned(p.number());
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int check = -1;
		for (int i = 0; i < m_lineupSize && check == -1; i++) {
			if (type == m_lineup[i]->type()) {
				check = i;
			}
		}
		return check;
	}

	void PreTriage::load()
	{
		ifstream fin(m_dataFilename);
		Patient* p = nullptr;
		char c = char(0);
		int i = 0; 
		cout << "Loading data..." << endl;
		if (fin && fin.get(c)) {
			fin >> m_averCovidWait;
			fin.ignore();
			fin >> m_averTriageWait;
			fin.ignore(2000, '\n');
			
			for (i = 0; i < maxNoOfPatients && fin; i++) {
				fin >> c;
				if (!fin.fail()) {
					if (c == 'C') {
						p = new CovidPatient;
					}
					else {
						p = new TriagePatient;
					}
					fin.ignore();
					p->fileIO(true);
					fin >> *p;
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize = i + 1;
				}
			}	
			if (!fin.eof()) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}
			cout << m_lineupSize << " Records imported..." << endl;
		}
		else {
			cout << "No data or bad data file!" << endl;
		}
		cout << endl;
	}

}