/* -----------------------------------------------------------
Workshop 08
Module: LblShape
Filename: LblShape.h
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
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include "Shape.h"

namespace seneca {

   class LblShape : public Shape    {
      // Dynamically allocated label for the shape
      char* m_label = nullptr;
   protected:
      // Returns the label string for derived classes to access
      const char* label() const;

   public:
      // Default constructor
      LblShape();
         //m_label = nullptr;
     

      // Constructor with label initialization
      LblShape(const char* label);
         //m_label = nullptr;
         //Utils::alocpy(m_label, label);
      

      // Copy constructor and assignment operator are deleted to prevent copying
      LblShape(const LblShape&) = delete;
      LblShape& operator= (const LblShape&) = delete;
      

      // Reads label specifications from input stream

      void getSpecs(std::istream& istr);

      

      // Destructor to release dynamically allocated memory
      virtual ~LblShape();
     
   };
}

#endif // !SENECA_LABELEDSHAPE_H
