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
V0.8    2025/03/26 Opened Files, read instructions, created Shape.cpp interface class (function defination)  for the two helpers for out/in operators 
V0.9    2025/01/27 added logic for the out/in operator overloads, so it takes the Shape object and calls draw or getSpecs methods
V1.0    2025/01/27 Tested, Debuged , and Ready for submission
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

