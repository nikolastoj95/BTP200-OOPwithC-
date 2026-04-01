/* Citation and Sources...
Final Project Milestone 3: 
Module: Billable
Filename: Billable.cpp
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

#include "Billable.h"
#include "constants.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    void Billable::price (double value) {
    m_price = 0.0;
    if (value >= 0.0) {
        m_price = value;
    }
    
    }

    void Billable::name (const char* name){
    delete[]  m_name ;
    m_name = nullptr;
        if (name != nullptr) {
        m_name = ut.alocpy(name);
    }
    }

    Billable::Billable() {
    m_name = nullptr;
    m_price=0.0;
    }

    //copy constructor
    Billable::Billable(const Billable& src){
        m_name = nullptr;
        m_price = 0.0;
        *this = src;
    }

    //copy assignment operator

    Billable& Billable::operator= (const Billable& billa) {
        if (this != &billa) {
            delete [] m_name;
            m_name = nullptr;

            if (billa.m_name ) {
                m_name = ut.alocpy(billa.m_name); // deep copy
            }

            m_price = billa.m_price; // copy price
        }

        return *this;
        
        
    }

    //virtual methods

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char*() const {
        return m_name;
    }

    // virtual destructor 
    Billable::~Billable() {
        delete [] m_name;
    }

    //operator overloads

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }
    
    double& operator+=(double& money, const Billable& B) {

        /*
        like
        double total = 0.0 
        total += item
        */
        money += B.price();
        return money;


    }

            

};