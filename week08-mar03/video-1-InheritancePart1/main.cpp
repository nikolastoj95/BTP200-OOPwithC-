#include <iostream>
// inheritance  -- relationship between two user defined  types in C++
// [something] -- inherited to --> [other thing]
//Dog  --> Domesticate Dog 
//Dog --> Wild Dog 
//Animal --> Dog -- Dog is a kind of Animal 

class Animal { // base class
    char name[32];
    int age;
    // double weight;
    // bool isDomesticated;
    public:

    void set(const char* p_name, int p_age) {
        if (p_age > 0 && p_name !=nullptr) {
            age = p_age;
            strcpy(name, p_name);

        } else {
            name[0] = '\0';
            age=0;
        }

    }

    void print ()const{
        std::cout <<"Name: " << name  << ", age: " << age << std::endl;
    }
};

// Dog - derived class
//Animal - is base class
class Dog: public Animal  {  // public  - mode of inheritance 
    // derived class name : public base class name // derived class from Animal inherits Animals member functions, member fields
    char breed [32];
    public:
        void setBreed (const char* p_breed){
            breed[0] = '\0';
            if (p_breed != nullptr) {
                strcpy(breed, p_breed);
            }
        }
        void printB() {
            std::cout << "Breed: " << breed << std::endl;
        }
    
};

class Cat: public Animal {
    
 };



int main() {
    Dog dog1;
    Cat cat1;

    dog1.set("Max", 3);
    dog1.setBreed("Labrador");
    dog1.print();
    dog1.printB();

    return 0;
};