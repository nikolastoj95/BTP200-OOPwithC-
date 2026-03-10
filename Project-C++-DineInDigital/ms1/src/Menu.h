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
    };

    std::ostream& operator<< (std::ostream& ostr, const MenuItem& item);
};
#endif