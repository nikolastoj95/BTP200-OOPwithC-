/* Citation and Sources...
Final Project Milestone 1: 
Module: Menu
Filename: Menu.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/03  Preliminary release
2024/03/06  started creating Menu module, header as per requirments
2024/03/07 added MenuItem class added 4 attributes, constructor, display, valudation
2024/03/07 checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>

using namespace std;

namespace seneca {

    class MenuItem {
        //fields  //attributes
        char* m_menuContent; //dynamic text
        unsigned int m_numberIndent;
        unsigned int m_sizeIndent;
        int m_menuNumber;

        void setEmpty();

        public:
        
        MenuItem();

        MenuItem (const char* menuText = nullptr, unsigned int numInd = 0,unsigned int sizeInd =0, int numMenu= -1 );

        ~MenuItem();

        MenuItem(const MenuItem&) = delete;

        MenuItem& operator=(const MenuItem&) = delete;

        operator bool() const;

        std::ostream& display (std::ostream& ostr) const;

        std::ostream& display() const;
    };

    //std::ostream& operator<< (std::ostream& ostr, const MenuItem& item);
};
#endif