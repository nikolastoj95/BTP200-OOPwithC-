/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2026/02/13
// Author Nikola Stojanovic	partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cmath> // for round function
#include "Mark.h"

using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }
   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M)const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }
   Mark::operator bool() const {
      return isValid();
   }


   // returns the GPA not the m_value!!!
   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      // removes the constantness of m_grade!
      // You will learn this at the end of the semester.
      char* grade = const_cast<char*>(m_grade);

      int value = int(*this);
      grade[1] = grade[2] = '\0';
      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';
      return m_grade;
   }

   // student helper function implementations go here
   ostream& Mark::display (ostream& os) const {
     
      if (!isValid()) {
         if (m_type == GRADE) {
            os << "**";
         }  else {
            os << "***";
         }
        
         return os;

      }

      if (m_type == GPA) {
         os << setw(3) << fixed << setprecision(1) << (double)(*this);
      } else if (m_type == MARK) {
         os << setfill('_') << setw(3) << right << (int)(*this);
      } else { // GRADE
         os << setfill (' ') << setw(3) << left << (const char*)(*this);
      }

      return os;
   }

   ostream& display (const Mark& m, char type, ostream& os) {
      Mark a = m;
      a= MARK;
      a.display(os);

      if (type != MARK) {
         os << ": ";
         Mark b = m;
         b= type;
         b.display(os);
      }
      return os;
   }

   ostream& operator<< (ostream& os, const Mark& m) {
      return m.display(os);
   }

   istream& operator>> (istream& is, Mark& m){
      int val{};

      // Validation loop: continues until valid input is received
      while (true) {
         // Attempt to extract an integer from the input stream
         if (!(is >> val)) {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush entire line
            cout << "Invalid integer, try again.\n> ";
            continue; //Retry
         }

         // must be no trailing characters (only newline allowed)
         // Check for trailing non-digit characters (e.g., "77abc" or "77.0")
         char next = is.peek(); // Peek at next character without consuming it
         if (next != '\n') {
            // Trailing characters detected
            is.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush remaining line
            cout << "Invalid trailing characters. Please enter only an integer.\n> ";
            continue; // Retry
         }
          // No trailing characters, consume the newline to clear buffer
         is.get();

         // Validate that the integer is within acceptable range [0, 100]
         if (val < 0 || val > 100) {
            cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            continue;
            // Retry
         }

         // All validations passed: assign value to Mark object and exit loop
         m = val;
         break;
      }
      return is;
      
   }

   ifstream& operator>>(ifstream& ifs, Mark& m) {
      int val{}; // values
      char comma{}; // commas
      char t{}; // types

      ifs >> val;
      if (ifs) {
         ifs >> comma;  // should be ','
         ifs >> t;      // 'M', 'G', 'R'
         if (ifs) {

            m = val;
            if (t == 'M') {
               m = MARK;  
            } else if (t == 'G') {
                m = GPA;
            } else if (t == 'R') {
               m = GRADE;
            }
              
         }
         ifs.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      return ifs;
   }

   double operator+(double v, const Mark& m) {
      return v + m.raw();
   }
   int operator+(int v, const Mark& m) {
      return v + (int)m; // your int cast already rounds
   }

   double operator-(double v, const Mark& m) {
      return v - m.raw();
   }
   int operator-(int v, const Mark& m) {
      return v - (int)m;
   }

   // friend operators: must access m_value directly
   double operator/(double v, const Mark& m) {
      return v / m.m_value;
   }
   int operator/(int v, const Mark& m) {
      return v / (int)(m.m_value + 0.5);
   }


}