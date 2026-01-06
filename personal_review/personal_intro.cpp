/*
 Personal Introduction Program
 By: Nikola Stojanovic
 Date: January 2, 2026
 Description: The program displays personal infp about me,
 in a formatted way on the condole
*/

#include <iostream>

int main() {
    //Display Header
    std::cout << "=============================="<< std::endl;
    std::cout << "\tPERSONAL INTRO"<< std::endl;
    std::cout << "=============================="<< std::endl;
    // display greeting with name
    std::cout << "NAME: Nikola Stojanovic." << std::endl;

    //hometown
    std::cout<< "HOMETOWN: TORONTO" <<std::endl;

    // some personal
    std::cout << "FAVORITE PROGRAMMING LANGUAGE: JAVA" << std::endl;

    // display current role/occupation
    std:: cout << "ROLE: Data Analysit at Amazon." << std::endl;

    // display message Why I am taking this course
    std::cout << "\n\tWHY I'M TAKING THIS COURSE" << std::endl;
    std::cout << "\t----------------------------" << std::endl;
    std::cout << "As I already took  and master other lanuages " << std::endl;
    std::cout << "such as python, javasrcipt, java, Sql," << std::endl;
    std::cout << "I want to learn C++ as well" << std::endl;
    // closting message 
    std::cout << "\nThank you for reading my inroduction!" << std::endl;

    //footer
    std::cout << "=============================="<< std::endl;

    return 0;

}