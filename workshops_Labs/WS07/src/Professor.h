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
        //  (1% * salary()) * m_numSections
       double devPay() const;
       
    public:
        Professor();
            // m_subjectName = nullptr;
            // m_numSections = 0;
      

        Professor(const char* name, const char* nameSubject, int numSections, size_t employeeNo, double salary );  //: Employee(name, employeeNo, salary );

        Professor (const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;

        ~Professor();
        //delete[] m_subjectName;
        // m_subjectName = nullptr;

        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout)const;
        std::ostream& title(std::ostream& ostr = std::cout)const;


        




    };




}
#endif // !SENECA_PROFESSOR_H