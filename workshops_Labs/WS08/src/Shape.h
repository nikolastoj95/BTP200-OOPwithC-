/* -----------------------------------------------------------
Workshop 08
Module: Shape
Filename: Shape.h
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
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {

   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw (std::ostream& ostr )const = 0;
      
      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(std::istream& istr) = 0;
      

      // Virtual destructor to ensure proper cleanup of derived class objects

      virtual ~Shape(){};
      
   };

   // Operator overload to handle output stream, relies on draw function

   std::ostream& operator<< (std::ostream& ostr, const Shape& S);
   

   // Operator overload to handle input stream, relies on getSpecs function
   std::istream& operator>> (std::istream& istr, Shape& S);
  

}

#endif // !SENECA_SHAPE_H
