/* Citation and Sources...
Final Project Milestone 3: 
Module: Food
Filename: Food.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/30  added Function Signtures, for Food class inherited from Billable according to requirements
2024/03/31  tested, debugged, ran
2024/03/31  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include <iostream>
#include <fstream>
#include "constants.h"
#include "Billable.h"

using namespace std;

namespace seneca {
    
    class Food  : public Billable {
        //attributes
        bool m_ordered{};
        bool m_child{};

        char* m_customize{}; // dynamically allocated c string

    public:
        Food ();

        //copy constructor
        Food(const Food& src);

        // copy assignment
        Food& operator= (const Food& src);

        std::ostream& print(std::ostream& ostr = cout) const override; 

        virtual bool order()  override;

        bool ordered() const override;

        std::ifstream& read(std::ifstream& file) override;

        double price() const override;

        ~Food();
        
    };
};
#endif