/* Citation and Sources...
Final Project Milestone 2: 
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/03  Preliminary release
2024/03/07  created Menu.cpp logic for member functions
2024/03/08   added validations, statments to display
2024/03/09  Debugged, Tested, run in main, works, done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Menu.h"
#include "constants.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    void MenuItem::setEmpty() {
        m_menuContent = nullptr;
        m_numberIndent = 0;
        m_sizeIndent = 0;
        m_menuNumber = -1;
    }

  

    MenuItem::MenuItem (const char* menuText , unsigned int numInd ,unsigned int sizeInd , int numMenu ){
            setEmpty();
            
            if (menuText == nullptr) return;
            if (menuText[0] == '\0') return;
            if (ut.isspace(menuText)) return;
            if (numInd  > 4) return;
            if (sizeInd > 4) return;
            if (numMenu > (int)MaximumNumberOfMenuItems) return;

            m_menuContent = new char[ut.strlen(menuText) +1];
            ut.strcpy( m_menuContent, menuText);
            m_numberIndent = numInd;
            m_sizeIndent = sizeInd;
            m_menuNumber = numMenu;
     };

     MenuItem::~MenuItem() {
        delete[] m_menuContent;
        setEmpty();

     }

     MenuItem:: operator bool() const {
        return m_menuContent != nullptr;
        // true if it is vaild Menu Item -> it is not nullptr
        // fasle if it is nullptr, -> in Safe Empty Sate
     }

   
    ostream& MenuItem::display (ostream& ostr) const {
        if (!*this) {
            // Menu Item is invalid
            ostr << "??????????";
            return ostr;
        }
        // continue if m_content id not null

        for (unsigned i = 0; i< m_numberIndent * m_sizeIndent; i++) {
            ostr << ' ';
        }
        if (m_menuNumber >= 0) {
            ostr.width(2);
            ostr << m_menuNumber << "- ";
        }

        const char* ptr = m_menuContent;
        while (*ptr && ut.isspace(*ptr)) {
            ptr++;
        }
        
        ostr << ptr;

        return ostr;
    }

    Menu::Menu (const char* title, const char* exitText, unsigned indentNum, unsigned indentSize  ) 
    :  m_indentNum(indentNum),
       m_indentSize(indentSize),
       m_numMenuItems(0) ,
       m_title(title,indentNum, indentSize,-1),
       m_exitOption(exitText, indentNum, indentSize,0),
       m_selEntryPrompt("> ",indentNum, indentSize, -1 ) // prompt row can be -1
    //   m_indentNum(indentNum),
    //   m_indentSize(indentSize),
    //   m_numMenuItems(0) 
      {
        for (unsigned int i =0; i < MaximumNumberOfMenuItems; i++) {
            m_items[i] = nullptr;
        }

      }

       Menu& Menu::operator<< (const char* menuItemText) {
         if (m_numMenuItems < MaximumNumberOfMenuItems)    {
            int row =  m_numMenuItems +1;

            //Dynamiclly allocate a new Menu Item
            m_items[m_numMenuItems] = new MenuItem(
                menuItemText,
                m_indentNum,
                m_indentSize,
                row
            );

            //Increase count

            m_numMenuItems++;


         }



        return *this;
       }

       Menu::~Menu(){
        for (unsigned int i =0; i < MaximumNumberOfMenuItems; i++) {
            if (m_items[i] != nullptr) {
                delete m_items[i]; // deleteing single object
                m_items[i] = nullptr;
            }  
        }
       }

        size_t Menu::select() const {
            /*
            Display title
            display() each menu item
            display() exit option
            display() prompt >
            read int form user, if it is correct one
            validate int is between 0 and num of items 0-20 only
            return int
            
            */

            if (m_title) {
                //if there 
                m_title.display() <<endl;
            }
            //2. Display each Menu Item
            for (unsigned int i =0; i< m_numMenuItems; i++){
                if (m_items[i]){
                    m_items[i]->display() << endl;
                }
            }
            //3. DIsplay Exit Option
            if (m_exitOption) {
                m_exitOption.display() << endl;
            }

            //4. Display Selection Prompt
            m_selEntryPrompt.display();

            int choice {};
            // cin >> choice;

            choice = ut.getInt(0,m_numMenuItems);

            //6. return choosen choice
            return  choice;
        }
        size_t operator<<(std::ostream& ostr, const Menu& m) {
            // if output stream is cout, run the menu
            if (&ostr == &std::cout) {
                return m.select();
            }
            //otherwise do not do anything
            return 0;
        }


       


      

    


    //  ostream& operator<<(ostream& ostr, const MenuItem& item) {
    //     return item.display(ostr);
    // }

}