/* -----------------------------------------------------------
Workshop 08
Module: Shape
Filename: Shape.cpp
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
#include "Shape.h"

using namespace std;

namespace seneca {
    
    std::ostream& operator<< (std::ostream& ostr, const Shape& S) {
        S.draw(ostr);
        return ostr;
    }

    std::istream& operator>> (std::istream& istr, Shape& S) {
        S.getSpecs(istr);
        return istr;
        
    }



}

