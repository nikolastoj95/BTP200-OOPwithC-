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

        
            // if (menuText != nullptr) {
            //     m_menuContent = new char[strlen(menuText) +1];
            //     strcpy( m_menuContent, menuText);
            // } else {
            //     menuText = nullptr;
            // }
            // if (menuText == nullptr || menuText[0] == '\0' || ut.isspace(menuText) ) {
            //      m_menuContent = nullptr;
            // } else {
            //     m_menuContent = new char[ut.strlen(menuText) +1];
            //     ut.strcpy( m_menuContent, menuText);
            // }

            // if (numInd  > 4) {
            //     m_numberIndent = 0;
            // } else {
            //     m_numberIndent = numInd;
            // }


            m_menuContent = new char[ut.strlen(menuText) +1];
            ut.strcpy( m_menuContent, menuText);
            m_numberIndent = numInd;
            m_sizeIndent = sizeInd;
            m_menuNumber = numMenu;
     };

     MenuItem::~MenuItem() {
        delete[] m_menuContent;
     }

     MenuItem:: operator bool() const {
        return m_menuContent != nullptr;
        // true if it is vaild Menu Item -> it is not nullptr
        // fasle if it is nullptr, -> in Safe Empty Sate
     }

   
    ostream& MenuItem::display (ostream& ostr) const {
        if (!*this) {
            // Menu Item is invalid
            ostr << "?????????";
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

    // ostream &MenuItem::display() const{
    //     return display(cout);
    // }

     ostream& operator<<(ostream& ostr, const MenuItem& item) {
        return item.display(ostr);
    }













}


