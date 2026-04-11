#include <iostream>

#include "Student.h"
#include "Utils.h"
using namespace std;

namespace seneca {
    Person::Person(){
        name = nullptr;
        cout << "Person()"<<endl;
    };

    Person::Person(const char* n) {
        cout<< "Person(const char* n)"<<endl;
        if (n != nullptr) {
            name = new char [NC +1]; // allocate memory
            ut.strcpy(name, n);
        }
    }
    void Person::displayName(std::ostream& os) const {
        os<< "Name: " << name  << ' ';
    }
    void Person::displayName(std::ostream& os, const char* msg) const {
        os<< msg << name << ' ';
    }

    Person::~Person(){
        cout << "\nBCDestrc" << endl;
        delete [] name; // deallocates memory name // char
        name = nullptr;
    }



    

    Student ::Student() {
        cout << "Student()"<<endl;
        stuNo = 0;
        grade = nullptr;
        ng = 0;
    }

    Student::Student(const char* n, int stId, const float* grd, int numGrad) : Person (n) {
        cout << "Student(const char* n, int stId, const float* grd, int numGrad)"<<endl;
        if (grd != nullptr && numGrad > 0) {
            ng = numGrad;
            grade = new float [NG];

            for (int i = 0 ; i< ng ; i++) {
                grade[i] = grd[i];
            }
        }

        if (stId > 0){
            stuNo = stId;
        } 

    }

    Student::~Student() {
        cout << "\nDCDestrc" << endl;
        delete[] grade;
        grade = nullptr;
    }

    void Student::displayName(std::ostream& os)const  {
        Person::displayName(os); // shadowing  // call base class display name
        os << "Student Number: "<< stuNo << ' '<< "Grades: " << endl;
        for (int i = 0 ; i< ng ; i++){
           os<<  grade[i] ;
           if (i< ng -1) {
            os<< ", ";
           }
        }
}
}