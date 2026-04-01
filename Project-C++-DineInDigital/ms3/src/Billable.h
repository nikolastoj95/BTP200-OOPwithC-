/* Citation and Sources...
Final Project Milestone 3: 
Module: Billable
Filename: Billable.h
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
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "constants.h"

using namespace std;

namespace seneca {

    class Billable {
        //attributes
        char* m_name; // dynamically allocated c string 
                        //holds name or descrip of item
        double m_price; // double for the base price of item
    protected:
        void price (double value); 
        void name (const char* name); 
            
    public:
        Billable();

        //copy constructor
        Billable(const Billable& src);

        //copy assignment operator
        Billable& operator= (const Billable& billa);

    
        //virtual methods
        virtual double price() const;

        operator const char*() const;

        // pure virtual methods (implemented in derived classes)
        virtual std::ostream& print(std::ostream& ostr = cout) const = 0;

        virtual bool order()  = 0;

        virtual bool ordered() const = 0;

        virtual std::ifstream&  read(std::ifstream& file) = 0;


        // virtual destructor
        virtual ~Billable();
    };

    //operator overloads

    double operator+(double money, const Billable& B);

    double& operator+=(double& money, const Billable& B);



};
#endif