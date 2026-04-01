/* Citation and Sources...
Final Project Milestone 3: 
Module: Drink
Filename: Drink.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/30  defination functions, methods for Drink class
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



#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include "Utils.h"


using namespace std;

namespace seneca{

    std::ostream& Drink::print(std::ostream& ostr ) const  {
        // 1. Name (28 chars, padded with dots)
       
        const char* nm = Billable::operator const char *();
        ostr << left << setw(28) <<setfill('.') << (nm ? nm : "") << setfill(' ');


        // 2. Size (5 chars)
        if (!ordered()) {
            ostr << ".....";
        } else {
            switch (m_size)
            {
            case 'S':
                ostr << "SML.."; break;
            case 'M':
                ostr << "MID..";break;
            case 'L':
                ostr << "LRG..";break;
            case 'X':
                ostr << "XLR..";break;
        
            default:
                ostr << ".....";break;
                break;
            }
        }

        //3. price (7 spaces, right - justified, 2 decimals)
        ostr << right<< setw(7) <<fixed << setprecision(2) <<price();

        return ostr;
    }

     bool Drink::order() {
        cout << "         Drink Size Selection\n";
        cout << "          1- Small\n";
        cout << "          2- Medium\n";
        cout << "          3- Larg\n";
        cout << "          4- Extra Large\n";
        cout << "          0- Back\n";
        cout << "         > ";


        int choice{};
        cin >> choice;

        switch (choice)
        {
        case 1:
            m_size = 'S';
            return true;
        case 2:
            m_size = 'M';
            return true;
        case 3:
            m_size = 'L';
            return true;
        case 4:
            m_size = 'X';
            return true;
        case 0:
            m_size = '\0';
            return false;
        
        default:
            m_size = '\0';
            return false;
        }

    }

    bool Drink::ordered() const {
        return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
    }

    std::ifstream& Drink::read(std::ifstream& file) {
        char drinkName[256]{};
        double basePrice{};

        // read name up to comma

        file.getline(drinkName, 256,',');

        //read price
        file >> basePrice;

        // 

        if (file) {
            file.ignore(1000,'\n');

            Billable::name(drinkName);
            Billable::price(basePrice);
            m_size = '\0'; 
        }

        return file;
        
    }

    double Drink::price() const {
        double base = Billable::price();

        if (!ordered() || m_size =='L') {
            return base;
        } else if (m_size == 'S') {
            return base *0.5; // half the price
        } else if (m_size == 'M'){
            return base *0.75;
        } else if (m_size == 'X'){
            return base *1.5;
        }
        return base;
    }

   

};