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
V0.8    2025/03/18 Opened File, read instructions, created the logic for the  required methods, constructors, validation, displaying, reading files 
V0.9    2025/01/19 Created in write, read in Professor class to show the number of sections, subject name, and called base class method to display those first 
V1.0    2025/01/20 Tested, Debuged , and Ready for submission
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