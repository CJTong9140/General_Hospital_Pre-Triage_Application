/* Citation and Sources...
Final Project Milestone
Module: Menu
Filename: Menu.cpp
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
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std; 
namespace sdds {
	void Menu::display() const
	{
		cout << m_text << endl
			 << "0- Exit"<< endl; 
	}

	Menu& Menu::setContent(const char* MenuContent)
	{
		if (MenuContent) {
			deallocate();
			m_text = new char[strlen(MenuContent) + 1]; 
			strcpy(m_text, MenuContent); 
		}
		return *this; 
	}

	void Menu::deallocate()
	{
		delete[] m_text; 
		m_text = nullptr; 
	}

	Menu::Menu() : m_text(nullptr), m_noOfSel(0)
	{
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections): Menu()
	{
		setContent(MenuContent); 
		m_noOfSel = NoOfSelections; 
	}

	Menu::Menu(const Menu& copyFrom) : Menu()
	{	
		setContent(copyFrom.m_text); 
		m_noOfSel = copyFrom.m_noOfSel; 
	}

	Menu::~Menu()
	{
		deallocate(); 
	}

	int& Menu::operator>>(int& Selection)
	{
		display(); 
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option "); 
		return Selection; 
	}


}