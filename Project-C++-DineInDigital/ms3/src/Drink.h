/* Citation and Sources...
Final Project Milestone 3: 
Module: Drink
Filename: Drink.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/25  Preliminary release
2024/03/19  added constructors, to Menu class initalized Menu item attbutes as well added logic to constructor, deconsructor 
2024/03/19  added  logic for operator overload << to add menu items titles, to object, added to select() which shows the whole menu, and able to select and display
2024/03/20  tested, debugged, ran
2024/03/21  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include <iostream>
#include <fstream>
#include "constants.h"
#include "Billable.h"

using namespace std;

namespace seneca {

    class Drink : public Billable{
        //attrubutes
        char m_size {}; // 'S', 'M', 'L', 'X' 
        // setting to {} is to '\0' which is safe empty state
    public:

        std::ostream& print(std::ostream& ostr = cout) const override; 

        virtual bool order()  override;

        virtual bool ordered() const override;

        virtual std::ifstream& read(std::ifstream& file) override;

        // double price() const override;

        double price() const override;





    };

};
#endif