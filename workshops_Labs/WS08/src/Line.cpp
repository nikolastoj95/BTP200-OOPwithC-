/* -----------------------------------------------------------
Workshop 08
Module: Line
Filename: Line.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2026/03/26 Opened Files, read instructions, created Line.cpp (defination file) concrete class inheriting LblShape class
V0.9    2026/01/27 added function logic for Line class,  added logic to  constructors to accept length of label and label , added logic to two overridden functions draw() and getSpecs()
V1.0    2026/01/27 Tested, Debuged , and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>

#include "Line.h"
#include "Utils.h"

namespace seneca {

   Line:: Line() : LblShape() {
        m_length = 0;
   }

    Line::Line(const char* label, int length) : LblShape(label) {
        bool valid = length >= 0 ;

        if (valid) {
            m_length = length;
        } else {
            m_length = 0;
        }

        if (label && m_length < (int)ut.strlen(label)) {
            m_length = ut.strlen(label);
        }
    }

    void  Line::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr); // calls getspecs function from base class to read the label

        // read the length
        istr >> m_length;

        // Ignore reat of the line including new line
        istr.ignore(1000, '\n');

    }

    void Line::draw (std::ostream& ostr )const {
        if (m_length > 0 && label() != nullptr ) {
            ostr << label() << '\n';
            for (int i = 0; i < m_length ; i++) {
                ostr << '=';
            }
            
        }

    }
}