/* -----------------------------------------------------------
Workshop 07
Module: Professor
Filename: Professor.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2025/03/10 Opened File, read instructions, created the required methods, functions
V0.9    2025/01/13 Ran tests, debugged, Works, added citation on the top
V1.0    2025/01/13 Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    double Professor::devPay() const {
        return (0.01 * salary()) * m_numSections;
    }

    Professor::Professor () {
        m_subjectName = nullptr;
        m_numSections = 0;
    }
     Professor::Professor(const char* name, const char* nameSubject, int numSections, size_t employeeNo, double salary ) : Employee(name, employeeNo, salary ) {
        
        bool valid = nameSubject != nullptr && numSections >= 0;
        if (valid) {
            //accept data 
             m_subjectName = ut.alocpy(nameSubject);
             m_numSections = numSections;

        } else {
            m_subjectName = nullptr;
            m_numSections = 0;
        }
       

     }

     Professor::~Professor(){
        delete[] m_subjectName;
        m_subjectName = nullptr;
     }

    std::ostream& Professor::title(ostream& ostr)const{
        Employee::title(ostr);
        return ostr <<" Teaching Subject     | Sec # | $Dev Pay |";
   }

    std::istream& Professor::read(std::istream& istr ){
        // Name, Employee Num, Salary, Subject Name, Number of Sections
        // first Read Employees class's part its own read function then do Professor's read method
       
        Employee::read(istr);  // reads first 3 fields // Name, Emp No, Salary 
        istr.ignore(); // stops before comma after salary, ignore it so it can read fields after it 

        // read subject name
        char buffer[1024];
        istr.getline(buffer, 1024, ',');
        
        ut.alocpy(m_subjectName, buffer); // setting subject name attribute

        // Read number of  Sections
        istr >> m_numSections;
        istr.ignore(); // ignore new line
        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr )const {
        
        Employee::write(ostr);
        ostr << " ";
        ostr.width(20); // sets width of 20 
        ostr.setf(std::ios::left); // left padding 
        char subjectPrint[21]{};
        if (m_subjectName) {
            if (ut.strlen(m_subjectName) > 20)
            {
                // if subject name is > 20 characters, shortern to 20
                ut.strcpy(subjectPrint, m_subjectName, 20);
                ostr << subjectPrint; // print subjectName 
            }
            else
            {
                // if shorter than 20 charcters, just print it 
                ostr << m_subjectName ;
            }
        } else {
            ostr << "";
        }
        
        ostr.unsetf(std::ios::left);
        ostr << " | "; 

        // print in num ber sections

        ostr.width(5);
        ostr.setf(std::ios::right);
        ostr<< m_numSections ;
        ostr.unsetf(std::ios::right);
        ostr << " | ";

        // print dev pay
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr.width(8);
        ostr << devPay() ;
        ostr << " |";

        return ostr;

    }

    std::ostream& operator<<( std::ostream& ostr, const Professor& P ) {
        // helper to print output,calls professors write method
        return P.write(ostr);

    }
    std::istream& operator>>( std::istream& istr, Professor& P ) {
        // helper to read input, calls Professor's read method
        return P.read(istr);
    }

}