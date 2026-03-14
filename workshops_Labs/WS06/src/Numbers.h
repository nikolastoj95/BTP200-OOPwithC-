/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* -----------------------------------------------------------
Workshop 06
Module: Numbers
Filename: Numbers.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/03/10 Opened File, read instructions, created the required methods, functions
V0.8    2025/03/11 Added Functions required to implement numberCount, load, save, copy assignment, copy constructor,  append operatior, display 
V0.9    2025/01/13 Ran tests, debugged, Works, added citation on the top
V1.0    2025/01/13 Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>

using namespace std;
namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      double average()const;
      double max()const;
      double min()const;

      bool load();
      void save() const;
      int numberCount() const;
   public:
      Numbers();
      Numbers(const char* filename);
      ~Numbers();
      Numbers(const Numbers& other);
      Numbers& operator=(const Numbers& other);
      Numbers& operator+=(double value);
      ostream& display(ostream& ostr) const;
      

   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SENECA_NUMBERS_H_

