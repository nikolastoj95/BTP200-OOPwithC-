/* -----------------------------------------------------------
Workshop 08
Module: Rectangle
Filename: Rectangle.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2026/03/26 Opened Files, read instructions, created Rectangle.cpp (defination file) concrete class inheriting LblShape class
V0.9   2026/01/27  added function logic for Rectangle class, added m_width and m_height fields for the rectangle frame, added constructors to accept length of label, label, width and height , added two overridden functions draw() and getSpecs(),
                   overidded the two methods draw and getSpecs reads info like width, height and label from base class and outputs with draw for a rectangle to be around the label
V1.0    2026/01/27 Tested, Debuged , and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>

#include "Rectangle.h"
#include "Utils.h"

namespace seneca{
    Rectangle::Rectangle() :  LblShape() {
        m_width = 0;
        m_height =0;
    }

    Rectangle:: Rectangle(const char* lab, int width, int height ): LblShape(lab) {
        if (height < 3  ) {
            m_height = 3;
            
        } else {
            m_height = height;
        }

        int minWidth = (label() ? ut.strlen(label()) :0 ) +2;

        if (width < minWidth) {
            m_width = minWidth;
        } else {
            m_width = width;
        }

        // if (m_width < (ut.strlen(label()+2) ) ) {
        //     m_width = ut.strlen(label())  +2;
        // } else {
        //     m_width = width;
        // }
    }

    void Rectangle::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr); // read label
        istr >> m_width;
        istr.ignore(1,',');
        istr >> m_height;
        istr.ignore(1000, '\n');

    }

    void Rectangle::draw (std::ostream& ostr )const {
        if ( m_width > 0 && m_height >0 && label() != nullptr) {
            //top border
            ostr << '+';
            for (int i =0 ; i < m_width -2; i++){
                ostr << '-';
            }
            ostr << '+' << '\n';

            //Label Line
            ostr << '|';
            ostr << std::left;
            ostr.width(m_width -2);
            ostr.fill(' ');
            ostr << label();
            ostr << '|' << '\n';

            //Empty Interior line
            for (int i = 0; i< m_height -3; i++){
                ostr << '|';
                ostr.width(m_width-2);
                ostr.fill(' ');
                ostr <<' '<<'|' << '\n';
            }

            //Bottom Border
            ostr <<'+';
            for (int i =0 ; i < m_width -2; i++){
                ostr << '-';
            }
            ostr << '+';

        }

    }
}