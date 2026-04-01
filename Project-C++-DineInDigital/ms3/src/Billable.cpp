/* Citation and Sources...
Final Project Milestone 3: 
Module: Billable
Filename: Billable.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/30  added the definations for the methods and functions for Billable class
2024/03/31  tested, debugged, ran
2024/03/31  checked and done
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