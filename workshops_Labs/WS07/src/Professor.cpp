#include <iostream>
#include "Professor.h"
#include "Utils.h"
// #include "Employee.h"

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
        std::cout << "Profess(5 arg constr)" << std::endl;
        
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
        // first Read EMployees class's part its own read function
       
        Employee::read(istr);  // reads  first 3 fields 
        istr.ignore();

        // read subject name
        char buffer[1024];
        istr.getline(buffer, 1024, ',');
        
        ut.alocpy(m_subjectName, buffer); // subject name

        // Read num Sec
        istr >> m_numSections;
        istr.ignore(); // ignore new line
        return istr;
    }

//    char buffer[1024];
//       istr.getline(buffer, 1024, ',');
//       ut.alocpy(m_name, buffer);
//       istr >> m_employeeNo;
//       istr.ignore();
//       return istr >> m_salary;



    std::ostream& Professor::write(std::ostream& ostr )const {
        
        //ostr << " here ";
        // ostr << " ";
        Employee::write(ostr);
        ostr << " ";
        ostr.width(20);
        ostr.setf(std::ios::left);
        char subjectPrint[21]{};
        if (m_subjectName) {
            if (ut.strlen(m_subjectName) > 20)
            {
                ut.strcpy(subjectPrint, m_subjectName, 20);
                ostr << subjectPrint;
            }
            else
            {
                ostr << m_subjectName ;
            }
        } else {
            ostr << "";
        }
        

        // ostr << " ";
        
        
        
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

    //  char name2print[16]{};
    //   if(m_name) ut.strcpy(name2print, m_name,15);
    //   ostr << "| ";
    //   ostr.width(15);
    //   ostr.setf(ios::left);
    //   ostr << name2print << " | ";
    //   ostr.unsetf(ios::left);
    //   ostr.width(6);
    //   ostr.fill('0');
    //   ostr.setf(ios::right);
    //   ostr << m_employeeNo << " |";
    //   ostr.fill(' ');
    //   ostr.setf(ios::fixed);
    //   ostr.precision(0);
    //   ostr.width(7);
    //   ostr << m_salary << " |";
    //   ostr.unsetf(ios::right);

    std::ostream& operator<<( std::ostream& ostr, const Professor& P ) {
        return P.write(ostr);

    }
    std::istream& operator>>( std::istream& istr, Professor& P ) {
        return P.read(istr);
    }



    

}