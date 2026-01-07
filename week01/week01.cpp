#include <iostream>

// Agenda
// Course introduction
// Transitioning from C to C++
// Type safety robustness of C++
// Encapsulation, class, attributes, and behaviour
// Namespace 
// Modular programming 
// Function overloading

// everything starts here main()

/*
Object-Oriented Programming - seeing program as a collection of objects 
    interacting with each other 
Object -  {data, method} what info it carrys, its behaviour 
Encapsulation - (diff things put together ) -  process of putting {data, method} together
Data Hiding -  encapsulation allows data hiding
Abstraction -  Data abstraction, Behaviour abstraction (common of all students)

Inheritance
Polymorphism
*/
// workshop 1 = relaized on Friday Jan 9, one week to work on it

/* - Encapsulation

struct Student { // structture , like Class
    int id;
    char name[32];
    int birthyear;
    char address[32];
};




*/

/* procedural programming, functional programming
* Diff between procedure and function
func1 -obj
func2- obj
func3 - obj
func4 -obj

int main (){
}

Function -- returns a value
Procedure -- does steps, 
OOP- collection of objects, interacting with each other
*/
int main() {
    char name[60] =  "Nikola";
    int id = 2;
    std::cout << "Name: " << name << " Id is " << id<< std::endl;
    return 0;
}