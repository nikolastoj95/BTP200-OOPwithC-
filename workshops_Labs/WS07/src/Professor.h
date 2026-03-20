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
V0.8    2025/03/18 Opened File, read instructions, created Professor class, derived class from employee, added 2 attibutes , function sigtures, overloaded methods (read,write,title), constructors (no-arg, 5-arg)
V0.9    2025/01/19 Added  private method, devPay that takes salary from Employee (Protected) used in Professor class, to calculate salary with num of sections, added two output, input helper methods to call read/write  
V1.0    2025/01/20 Ready for submission.
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