/* -----------------------------------------------------------
Workshop 07
Module: Professor
Filename: Professor.h
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
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include "Employee.h"
namespace seneca{

    class Professor : public Employee { 
        char* m_subjectName; // dynamically allocated C string
        int m_numSections;

        // returns a double, does not modify Professor obj so const
        //calculates addtional pay based on Num of sections 
        // (1% * salary()) * m_numSections
       double devPay() const;
       
    public:
        Professor();
            
        Professor(const char* name, const char* nameSubject, int numSections, size_t employeeNo, double salary );  //: Employee(name, employeeNo, salary );

        Professor (const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;

        ~Professor();

        std::istream& read(std::istream& istr = std::cin );
        std::ostream& write(std::ostream& ostr = std::cout)const ;
        std::ostream& title(std::ostream& ostr = std::cout)const ;

    };

    std::ostream& operator<<( std::ostream& ostr, const Professor& P );
    std::istream& operator>>( std::istream& istr, Professor& P );




}
#endif // !SENECA_PROFESSOR_H