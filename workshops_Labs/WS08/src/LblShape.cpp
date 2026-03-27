/* -----------------------------------------------------------
Workshop 08
Module: LblShape
Filename: LblShape.cpp
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

#include <iostream>
#include "LblShape.h"
#include "Utils.h"

namespace seneca{

    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::LblShape() {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* label) {
        bool valid = label != nullptr;
        if (valid) {
            // accept Data
            m_label = ut.alocpy(label);
        } else {
            m_label = nullptr;
        }
    }

    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }

   void  LblShape::getSpecs(std::istream& istr) {
        char temp[81];
        istr.getline(temp, 81,','); // read until comma

        delete[] m_label;
        m_label = nullptr;

        ut.alocpy(m_label, temp);

    }




}