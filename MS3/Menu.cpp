/* Citation and Sources...
General Hospital Pre-Triage Application
Module: Menu
Filename: Menu.cpp
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