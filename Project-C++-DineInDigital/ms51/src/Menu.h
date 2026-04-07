/* Citation and Sources...
Final Project Milestone 3: 
Module: Menu
Filename: Menu.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/25  Preliminary release
2024/03/18  added to Menu module added Menu class which has a Menu Item class
2024/03/18  added new attribures, constructors, to Menu class initalized Menu item attbutes as well 
2024/03/18  added function sigtures for operator <<, select()
2024/03/18  added function sigtures for a friend function for inseration operator overload into  ostream, and added get int for select()
2024/03/20  tested, debugged, ran
2024/03/21  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

using namespace std;

namespace seneca {

    class Menu; // Meny "has a" Menu Item // Menu owns Menu Item // forward declartion


    class MenuItem {
        friend class Menu; // Menu is allowed to access private parts 
        //fields  //attributes
        char* m_menuContent; //dynamic text
        unsigned int m_numberIndent;
        unsigned int m_sizeIndent;
        int m_menuNumber;

        void setEmpty();
        
        // MenuItem();

        MenuItem (const char* menuText = nullptr, unsigned int numInd = 0,unsigned int sizeInd =0, int numMenu= -1 );

        ~MenuItem();

        MenuItem(const MenuItem&) = delete;

        MenuItem& operator=(const MenuItem&) = delete;

        operator bool() const;

        std::ostream& display (std::ostream& ostr = cout ) const;

    };

    class Menu {
        //attributes 
        unsigned int m_indentNum;
        unsigned int m_indentSize;
        unsigned int m_numMenuItems;

        //Menu-level Menu Items
        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_selEntryPrompt;

        MenuItem* m_items[MaximumNumberOfMenuItems];
            // m_items[m_numMenuItems] = new MenuItem(...);
            // m_numMenuItems++;
    public:
        Menu(const char* title, const char* exitText = "Exit", unsigned indentNum = 0, unsigned indentSize = 3 );
            /*{



            }*/
        
        Menu(const Menu&) = delete;

        Menu& operator=(const Menu&) = delete;

        ~Menu();
        Menu& operator<< (const char* menuItemText);

        size_t select() const;

    };
    size_t operator<<(std::ostream& ostr, const Menu& m);
};
#endif