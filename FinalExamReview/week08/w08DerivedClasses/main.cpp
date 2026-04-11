#include <iostream>

#include "Student.h"

using namespace seneca;

void show(const Person*);

int main(){

    //Polymorphic Objects

    Person jane("Jane"); 
    float gh[] = {90.0, 98.8, 66.5, 50.4};
    Student john ("John",4567, gh, 4);

    Person* pJane = &jane; 
    /*
        static type: Person*
        dynamic type: points to a Person object
        dynamic type is Person
        NOT Polymorphism
        (base pointer -> base object)

    
    */
    Person* pJohn = &john;  
    /*static type is Person*
     Dynamic type is points to Student Object
     dynamic type is Student
    THis is Ploymorphic 

    (base pointer -> derived object)
    
    */



    Student* sJohn = &john; 
    /*
        static type: is Student*
        Dynamic Type: points to Student Object
        dynamic type is Student
        THIS NOT polymorphic

        (derived pointer -> derived object)
    */


    pJohn->displayName(std::cout);
    // this will call derived classes function and base class function

    pJane->displayName(std::cout);
    sJohn->displayName(std::cout);
    // john.displayName(std::cout);

    // // Instructor john ("John");
    // Person jane("Jane");
    // float gh[] = {90.0, 98.8, 66.5, 50.4};
    // Student harry ("Harry",4567, gh, 4);


    
    // harry.displayName(std::cout);
    // // harry.displayName(std::cout,"My Name is ");
    // // std::cout<<endl;

    // // Person jane1 ("Jane");
    // jane.displayName(std::cout);

    return 0;
}