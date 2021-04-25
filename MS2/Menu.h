/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
namespace sdds {
	class Menu {
		char* m_text; 
		int m_noOfSel; 
		void display() const; 
		Menu& setContent(const char* MenuContent); 
		void deallocate(); 
	public: 
		Menu(); 
		Menu(const char* MenuContent, int NoOfSelections); 
		Menu(const Menu& copyFrom); 
		// prevent assignment copying
		Menu& operator = (const Menu& copyFrom) = delete; 
		virtual ~Menu(); 
		int& operator >> (int& Selection); 
	};
}
#endif
