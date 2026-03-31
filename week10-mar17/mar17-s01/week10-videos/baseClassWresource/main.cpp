#include <iostream>
#include <cstring>

class Animal {

    char* name; // name of animal in dunamic memory // add protected 
protected:
    const char*  getName() const {
        return name;
    }
public:
    Animal(){
        std::cout<< "A-DCstr" << std::endl;
        name = nullptr;
    }
    Animal(const char* p_name){
         std::cout<< "A-CCstr" << std::endl;
        name = nullptr;
        if(p_name != nullptr){
            name = new char[strlen(p_name)+1];
            strcpy(name,p_name);
        }

    }

    //copy constructor  // to put one instance a1 into a3 
    Animal(const Animal& src) {
        name = nullptr; // name to nullptr
        // if (src.name){
        //     name = new char[strlen(src.name)+1];
        //     strcpy(name, src.name);
        // } else {
        //     name = nullptr;
        // }
        *this = src;
    }
    //copy assignment operator
    Animal& operator= (const Animal& anm){
        if (this !=  &anm) {
            // if this obj not object to be assigned (obj in param)
            if (name != nullptr)
                // trying to access memory not allowed to be deleted cause copy constructor is not allocated memory
                delete []name;
            name = nullptr;
            
            if (anm.name != nullptr){
                name = new char[strlen(anm.name)+1];
                strcpy(name, anm.name);
            }

        }
        return *this; // return current object
    }
    //display data
    std::ostream& operator << (std::ostream& os) const {
        return os << "Name: " << name;
    }



    ~Animal(){
        std::cout<< "A-Dstr" << std::endl;
        delete [] name;
        name= nullptr;
    }
};

//devried class Dog
class Dog : public Animal {
    //feilds  attributes 
    //bits for current year, previus year, previous- previus year, ... {5,2,7}
    int* numOfBites;
    int size; // size of array

public:
    // default constructor
    // constructor is not inherited like methods, fields 
    // automatically calls base class constructor
    Dog() : Animal("Spot") { // by default it will call default constructor  of the base class
        // to call bases class constructor  : name of base class () Dog() : Animal() {}
        //default values
      std::cout<< "D-DCstr" << std::endl;
      numOfBites = nullptr;
      size = 0;  
    }
    //custom constructor
    Dog(const char* p_name, const int* p_numBites, int p_size) : Animal (p_name){
        std::cout<< "D-CCstr" << std::endl;
        // set to default state
        numOfBites = nullptr;
        size = 0;
        if (p_numBites != nullptr && p_size > 0) {
            // set the attrubtes
            size = p_size;
            numOfBites = new int[size];
            for (int i =0 ; i< size; i++){
                numOfBites[i] =  p_numBites[i];
            }

        }
    }

    //display data
    std::ostream& operator << (std::ostream& os) const {
        //call Base Class method
       (Animal&) *this << os; // to display the name // manually call base class method
        //Animal(os);
        os <<  " Bites: ";
        for (int i = 0; i<size; i++){
            os << numOfBites[i] << (numOfBites ? "," :".");
        }
        return  os;
    }




    //destructor
    ~Dog(){
         std::cout<< "D-Destr" << "(" << (getName() != nullptr ?  getName() : "") << ")" << std::endl;
        delete[] numOfBites;
        // no need to call base class destructor, 
        //and end of logic of devried class it calls auto base class destructor
        
    }


};



// free helper operator
// change to dog class
// std::ostream& operator<< (std::ostream& os, Animal& anm) {
//     // this invokes calls the display method in class Animal

//    return anm<< os;
// }

// free helper operator
// change to dog class
std::ostream& operator<< (std::ostream& os, Dog& dg) {
    // this invokes calls the display method in class Animal

   return dg << os;
}

int main (){
    // if (0) {
    //      Animal a1 ("Jack"), a2 ("Don"); // create object

    //     std::cout<< a1 << std::endl <<a2 <<std::endl;
    //     //Name: Jack
    //     //Name: Don

    //     Animal a3 =  a1; // setting a3 to existing a1 obj // copy constructor

    //     std::cout <<a3 <<std::endl;
    //     //Name: Jack

    //     a1 = a2; // copy assignment // a1 is a2 now

    //     std::cout << a1 << std::endl;
    //     //Name: Don

    // }

    int numOfBites [] = {2, 5, 4, 3 };

    Dog dg; // create dg Dog obj
    {
        Dog dg1("Spot", numOfBites, 4); // copy name to base class
                                     // two numofBites,  size  Dervied class  to its own attributes
        //display
        std::cout << dg1 <<std::endl;

        /*
        A-CCstr
        "D-CCstr




        
        
        */

    
    }

    /*
    A-DCstr
    D-DCstr
    A-DCstr
    D-DCstr
    D-Destr
    A-Dstr
    D-Destr
    A-Dstr
    */

    /*
    
    
    
    */



   

    // without friend helper 
    // a1.operator<<(std::cout);
    // a1<< std::cout; // same as above


    return 0;
}