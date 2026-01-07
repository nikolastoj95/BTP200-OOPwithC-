#include <iostream> // input putput stream // the library that brings in cout

int main () {

    int id = 1001;
    char name [32] = "Jackson";

    //read data input
    // >> - extaction operator;
    // cin - object linked to input stream

    // std::cout << "Enter Your ID: ";
    // std:: cin >> id;
    // std::cout << "Enter Your Name: ";
    // std:: cin >> name;

    std::cout << "Enter your Id and Name: ";
    std::cin >> id >> name ; // chaining of extraction operations



    // in c printf()
    // in c++ use object std::cout console out object
    std::cout << "Hello World" << std::endl;
    //cout - is an object linked to output stream 
    //endl - rep newline character
    // << - insertion operator
    std::cout << "Name: {{" << name << "}}, Id: {{" << id << "}}" << std::endl; //chanong of insertion operations
    // insertt Name, var name, Id, var id, insert new line char
    return 0;
}