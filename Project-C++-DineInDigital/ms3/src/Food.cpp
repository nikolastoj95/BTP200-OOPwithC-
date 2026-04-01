/* Citation and Sources...
Final Project Milestone 3: 
Module: Food
Filename: Food.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/30  added function definations for Food class inherited from Billable
2024/03/31  tested, debugged, ran
2024/03/31  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>


#include "Food.h"
#include "Billable.h"
#include "constants.h"
#include "Utils.h"

using namespace std;

namespace seneca{

    Food::Food() {
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }
    //copy constructor
    Food::Food(const Food& src) : Billable(src) {
        m_ordered = src.m_ordered;
        m_child = src.m_child;
        m_customize = nullptr;

        if (src.m_customize) {
            m_customize = ut.alocpy(src.m_customize);
        }
    }


    // copy assignment

    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);

            m_ordered = src.m_ordered;
            m_child = src.m_child;

            delete[] m_customize;
            m_customize = nullptr;

            if (src.m_customize) {
                m_customize = ut.alocpy(src.m_customize);
            }
        }
        return *this;
    }



    // print

    std::ostream& Food::print(std::ostream& ostr) const {

        //1. Name (up to 25 chars, 28 spaces,  left, padded with  .  dots's)
        const char* nm = Billable::operator const char *(); // gets m_name

        ostr << left << setw(28) << setfill ('.') << (nm ? nm : "") << setfill(' ');

        //2. portion type

        if (!ordered()) {
            ostr << ".....";
        } else {
            // if ordered 
            if (m_child) {
                ostr << "Child";
            } else {
                ostr << "Adult";
            }
        }

        //3. price

        ostr << right<< setw(7) <<fixed << setprecision(2) <<price();


        //4. customizations

        if (m_customize  && &ostr == &cout) {
            ostr << " >> " << setw(0);
            for (int i = 0;  m_customize[i] && i <30 ; i++) {
                ostr << m_customize[i];

            }

        }
        return ostr;

    }



    // order

    bool Food::order() {

        cout << "         Food Size Selection\n";
        cout << "          1- Adult\n";
        cout << "          2- Child\n";
        cout << "          0- Back\n";
        cout << "         > ";

        int choice = ut.getInt(0,2);
       
        if (choice == 0 ) {
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }

        m_ordered = true;
        m_child = (choice ==2);

        cout << "Special instructions\n";
        cout << "> ";

        std::string instruction;

        getline(cin,instruction);

        delete[] m_customize;
        m_customize = nullptr;

        if (!instruction.empty()){
            m_customize = ut.alocpy(instruction.c_str());
        }

        return true;
    }

    // ordered

    bool Food::ordered() const {
        return m_ordered;
    }
    

    // read

    std::ifstream& Food::read(std::ifstream& file) {
        char foodName[256]{};
        double foodPrice{};

        file.getline(foodName, 256, ',');
        file >> foodPrice;

        if(file) {
            // if read is sucessfull 
            file.ignore(1000, '\n');

            // set the name, and price to the fields 
            this -> Billable::name(foodName);
            this -> Billable::price(foodPrice);

            m_child = false;
            m_ordered = false;
            delete [] m_customize ;
            m_customize = nullptr;
        }
        return file;
    }

    //price

    double Food::price() const {
        // get price
        double base = Billable::price();

        if (ordered() &&  m_child ) {
            return base * 0.5;
        } 
        return base;

    }




    Food::~Food() {
        delete [] m_customize;
    }
}