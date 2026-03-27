/* -----------------------------------------------------------
Workshop 08
Module: Rectangle
Filename: Rectangle.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2026/03/26 Opened Files, read instructions, created Rectangle.h (header file) concrete class inheriting LblShape class
V0.9   2026/01/27  added function sigtures for Rectangle class, added m_width and m_height fields for the rectangle frame, added constructors to accept length of label, label, width and height , added two overridden functions draw() and getSpecs()
V1.0    2026/01/27 Tested, Debuged , and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      int m_width{};
      // Height of the rectangle
      int m_height{};


   public:
      // Default constructor
      Rectangle();
      

      // Constructor that initializes label, width, and height
      Rectangle(const char* label, int width, int height );
      

      // Draws the rectangle using the label, width, and height
      void draw (std::ostream& ostr )const;

      

      // Gets specifications of the rectangle (label, width, height) from input
      void getSpecs(std::istream& istr);
      
   };

}

#endif // !SENECA_RECTANGLE_H
