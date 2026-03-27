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
V0.8    2025/03/26 Opened Files, read instructions, created LblShape.cpp (fucntion defination file) abstract class inheriting Shape interface
V0.9    2025/01/27  added function logic for label() to print the label, constructors to allocate memory for m_label field, getSpecs() function to read given label
V1.0    2025/01/27 Tested, Debuged , and Ready for submission
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