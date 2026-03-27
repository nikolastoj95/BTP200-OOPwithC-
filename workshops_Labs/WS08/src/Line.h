/* -----------------------------------------------------------
Workshop 08
Module: Line
Filename: Line.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2025/03/26 Opened Files, read instructions, created Line.h (header file) concrete class inheriting LblShape class
V0.9    2025/01/27 added function sigtures for Line class, added m_length field, added constructors to accept length of label and label , added two overridden functions draw() and getSpecs()
V1.0    2025/01/27 Tested, Debuged , and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h"
namespace seneca {

   class Line : public LblShape {
       // Length of the line
      int m_length{};

   public:
      // Default constructor
      Line();

      
      // Constructor that initializes label and length
      Line(const char* label, int length);
     

      // Draws the line, using the label and length
      void draw (std::ostream& ostr )const;
      

      // Gets specifications of the line (label and length) from input

      void getSpecs(std::istream& istr);
     
   };

}

#endif // !SENECA_LINE_H
