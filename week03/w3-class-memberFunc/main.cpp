#include <iostream>
using namespace std;

/*
Member Function (Method)
Types of Member functions
coding member functions
    - declaration
    - definition 
    - calling
*/

/* 2nd video  Data Privacy 
    - (private , public)
Privacy in struct and class
Accessing private data
*/

struct Country {
    char mName[32];
    unsigned int mArea;
    //some comment to test

    // create function to access data or attributes to write or to re
    // 1.  (write data in to it)  setter, or mutator , or modifer
    /*inline*/ void set(const char* name, unsigned area); //treated as inline function  // to recieve name and area
         

    //2. (read data from it ) getter, query, accesser 
        // reads data in the attributes and returns it
    const char* getName() const { //query functions
        return mName;
    }
    unsigned getArea() const{ // query functions
        return mArea;
    } 

    //Getter function designed to access the data but do not make any changes to it
        // query function
    //Setter function designed to set data to the attributes, and make changes to them can not be const

    //3.  Special member functions 
    // Constructor and destructor - designed to execute logic during the 
        // creation or destruction of object
    // Purpose is to -- be created properly and distroyed properly 

    // 3. query function display 
    void display() const {
        cout << "Country Name: " << mName << endl << "Country Area: " << mArea << endl;
    }

};

// struct name :: function name (){}
// below to access the class or struct set functions if it is defined in header file
 void Country::set(const char* name, unsigned area){ //treated as inline function  // to recieve name and area
         strcpy(mName, name);
         mArea = area;
    }

int main (void){

    Country ct;
    // invokeing a member function (set, get)
    ct.set("Serbia", 32546); // public access function 

    // strcpy(ct1.mName, "Serbia");

    // ct1.mArea = 34543; // setting data
    ct.display();
    
    return 0;
};