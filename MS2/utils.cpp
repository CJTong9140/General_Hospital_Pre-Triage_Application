/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
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
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt)
   {
       int value = 0;
       bool check = false;
       if (prompt != nullptr) {
           cout << prompt; 
       }

       do {
           cin >> value; 
           if (!cin) {
               cout << "Bad integer value, try again: ";
               cin.clear();   
               cin.ignore(3000, '\n'); 
           }
           else {
               if (cin.get() != '\n') {
                   cout << "Enter only an integer, try again: "; 
                   cin.ignore(3000, '\n');
               }
               else {
                   check = true; 
               }
           }
       } while (!check);
       return value;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       bool check = false; 
       int value = 0; 
       do {
           value = getInt(prompt);
           if (value < min || value > max) {
               prompt = nullptr;
               cout << errorMessage;
               if (showRangeAtError) {
                   cout << "[" << min << " <= value <= " << max << "]: "; 
               }   
           }
           else {
               check = true; 
           }
       } while (check == false); 
       return value; 
   }

   // Without using the string class
   char* getcstr(const char* prompt, istream& istr, char delimiter)
   {
       char* cstring = nullptr;
       char* returnedString = nullptr;
       int noOfChars = 0;
       int count = 1;

       if (prompt != nullptr) {
           cout << prompt;
       }
       cstring = new char[101];
       istr.getline(cstring, 101, delimiter);

       while (istr.fail()) {
           char* temp = nullptr;
           noOfChars = 100 + 100 * count;
           temp = new char[noOfChars + 1];
           strcpy(temp, cstring);
           delete[] cstring;
           cstring = temp;        
           cin.clear();
           istr.getline(&cstring[count * 100], 101, delimiter);
           count++;
       }
       
       returnedString = new char[strlen(cstring) + 1];
       strcpy(returnedString, cstring);
       delete[] cstring;
       return returnedString;
   }

   // The following is using the string class build in functions
   /*char* getcstr(const char* prompt, istream& istr, char delimiter)
   {
       string cstring; 
       char* returnedString = nullptr; 
       
       if (prompt != nullptr) {
           cout << prompt;
       }
       getline(istr, cstring, delimiter); 
       returnedString = new char[cstring.length() + 1];
       strcpy(returnedString, cstring.c_str()); 
       return returnedString;
   }*/
   
}