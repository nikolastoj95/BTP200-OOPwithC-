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
V0.8    2025/03/18 Opened File, read instructions, created the logic for the  required methods, constructors, validation, displaying, reading files 
V0.9    2025/01/19 Created in write, read in Professor class to show the number of sections, subject name, and called base class method to display those first 
V1.0    2025/01/20 Tested, Debuged , and Ready for submission
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
