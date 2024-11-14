# General Hospital Pre-Triage Application
This project is a hospital pre-triage application designed to register patients for Covid testing or general triage, 
estimate wait times, and manage patient admissions. It incorporates advanced C++ concepts, including encapsulation, 
inheritance, polymorphism, and memory management, to create a modular and efficient application.

## Project Overview
Build with C++11, the Pre-Triage Application allows hospital staff to:
- **Register Patients:**
Patients can be registered as either Covid or Triage patients with a unique ticket number and 
time of arrival.
- **Estimate Wait Time:**
Provides up-to-date wait times for patients based on patient category (Covid or Triage).
- **Admit Patients:**
Admits the next patient in line, prioritizing based on their ticket type and arrival time.
- **Data Persistence:**
Saves and loads patient data to/from files for ensuring continuity and efficient data handling.

## Core Modules  
### ***Milestone 1 (MS1): Utilities and Time Modules***
- Time and utils helper modules for input validation, time calculation, and memory-safe handling of user entries. 
- Dynamic memory allocation for strings without using the C++ string class.
### ***Milestone 2 (MS2): Menu and IOAble Interface***
- **Menu**: Dynamic menu system with foolproof input handling.
- **IOAble**: Interface enforcing standardized I/O methods for derived classes.
### ***Milestone 3 (MS3): Patient and Ticket Classes***
- **Patient**: Abstract base class containing patient data with virtual I/O methods.
- **Ticket**: Manages unique ticket numbers and arrival times.
### ***Milestone 4 (MS4): CovidPatient and TriagePatient Modules***
- Specialized classes for Covid and Triage patient with unique handling.
### ***Milestone 5 (MS5): PreTriage Module***
- Manages patient lineups, ticket assignment, and admissions, integrating all modules into a pre-triage workflow.

## Features
- **Encapsulation and Memory Management**: 
Adheres to the Rule of Three with dynamic memory allocation.
- **Unit Testing**: 
Tester programs validate each module's functionality, ensuring robust error handling.
- **Modular Design**: 
Milestone-based structure builds a clear, organized application.

## Key Learning Outcomes 
This project reinforced principles of object-oriented design, memory management, and practical applications of inheritance 
and polymorphism. It also enhanced my understanding of modular programming, unit testing, and efficient resource management.

## Setup Instructions
1. **Clone the Repository**: `git clone <repository-url>`
2. **Build the Project**: Ensure your compiler supports C++11, then use your C++ compiler to compile the source files.
3. **Run the Program**: Execute the main application file in your terminal or IDE.
