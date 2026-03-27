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
V0.8    2026/03/26 Opened Files, read instructions, created Shape.h interface class added the pure virtual functions draw(), getSpecs(), added virtual Decstructor
V0.9    2026/01/27 added 2 helper functions, that overload >>/ << (output, input operators) to work with Shape objects using getSpecs and draw methods
V1.0    2026/01/27 Tested, Debuged , and Ready for submission
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
