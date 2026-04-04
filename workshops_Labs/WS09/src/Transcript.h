/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
// Added attrubutes, Constructor, Rule of 3, overidden display function By:
// Nikola Stojanovic| 027 369 149  | nstojanovic@myseneca.ca | BTP200NAA
//
// Revision History
// -----------------------------------------------------------
// Name                 Date                 Reason
// Nikola Stojanovic    Friday April 3       Added to Transcript  Module header file with
//                                           two attributes, constructor, Rule of 3 and overidden display function from Marks class
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name 
      const char* m_studentName{}; //dynamiclly allocated memory 
      
      // unsigned integer or size_t student number
      unsigned int m_studentNum{};


   public:
      // Constructor
      Transcript( const char* stuName, unsigned int stuNumber);
            
      // Rule of Three

      //copy constructor
      Transcript(const  Transcript& other); // :Marks(other);

      //copy assignment operator
      Transcript& operator=(const Transcript& other);

      // overidden Virtial display Function
      std::ostream& display(std::ostream& ostr)const override;

      // Destructor
      ~Transcript();
   };
}
#endif // !SENECA_TRANSCRIPT_H


