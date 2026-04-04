/* -----------------------------------------------------------
Workshop 09
Module: Transcript
Filename: Transcript.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2026/04/03  Opened files, read requirments, studyed the Marks module, added the function definations logic for the constructor, rule of 3
V0.9    2026/04/03  Added the overidden function of display to show the name and number attributes of Transcript class and the content of  Marks Class by calling the base class method
V1.0    2026/04/03 Tested, Debuged , and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>
#include "Marks.h"
#include "Utils.h"
#include "Transcript.h"

using namespace std;

namespace seneca {

    Transcript::Transcript(const char* stuName, unsigned int stuNumber){
        m_studentName = nullptr;
        m_studentNum = 0;
        if ( stuName != nullptr && stuNumber > 0 ) {
            
            m_studentName = ut.alocpy(stuName);
            m_studentNum = stuNumber;    
        }
    }

    //copy constructor

    Transcript:: Transcript(const Transcript& other) : Marks(other) {
        m_studentName = nullptr;
        m_studentName = ut.alocpy(other.m_studentName);
        m_studentNum = other.m_studentNum;
    };

    //copy assignment operator
    Transcript& Transcript:: operator=(const Transcript& other){

        if (this != &other){
            // avoids self assingment
            Marks::operator=(other); // use copy assignment from base class part

            //free old name before copying
            delete[] m_studentName;

            m_studentName = ut.alocpy( other.m_studentName);
            m_studentNum = other.m_studentNum;
        }

        return *this; // return current obj

    };

    std::ostream& Transcript::display(std::ostream& ostr)const {
        // overide display function of Marks class
        // this display should print this
            /*
            [Student Name] ([Student Number])
            --------------------------------------------------------------------------
            existing Marks display content
            */
        ostr << m_studentName << " (" << m_studentNum << ")\n";
        ostr << "--------------------------------------------------------------------------\n";
        Marks::display(ostr);

        return ostr;

    };

    Transcript::~Transcript() {
        delete[] m_studentName;
        m_studentName = nullptr;
    };

            
};

