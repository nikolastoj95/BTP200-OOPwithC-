/* Citation and Sources...
Final Project Milestone 3: 
Module: Drink
Filename: Drink.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/30  added function sigmtures, for Drink concrete class inherited from Billable
2024/03/31  tested, debugged, ran
2024/03/31  checked and done
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