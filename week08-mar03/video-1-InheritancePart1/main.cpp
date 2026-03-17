#include <iostream>
// inheritance  -- relationship between two user defined  types in C++
// [something] -- inherited to --> [other thing]
//Dog  --> Domesticate Dog 
//Dog --> Wild Dog 
//Animal --> Dog -- Dog is a kind of Animal 

//video 2
// keyword - protected 

class Animal { // base class
// protected: // or do it like this
    char name[32];
    int age;
    // double weight;
    // bool isDomesticated;

    protected: // accessiable from derived class
        void setName(const char* p_name) {
            name[0] = '\0';
            if (p_name !=nullptr) {
                strcpy(name, p_name);
            }
        }
        void setAge (int p_age) {
            age = 0;
            if (p_age > 0) {
                age = p_age;
            }
        }

        const char* getName() const { // indirect access
            return name;
        }
        int  getAge() const {
            return age;
        }



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
        //direct access
        std::cout <<"Name: " << name  << ", age: " << age << std::endl;
    }
};

// Dog - derived class
//Animal - is base class
class Dog: public Animal  {  // public  - mode of inheritance 
    // derived class name : public base class name // derived class from Animal inherits Animals member functions, member fields
    char breed [32];
    void setBreed (const char* p_breed){
            breed[0] = '\0';
            if (p_breed != nullptr) {
                strcpy(breed, p_breed);
            }
        }
    public:
        
        void set(const char* p_name, int p_age, const char* p_breed) {
            if (p_age > 0 && p_name !=nullptr && p_breed != nullptr) {
                setAge(p_age);
                setName(p_name);
                setBreed(p_breed);

            } else {
                
                breed[0] = '\0';
            }

        }  
        
        void printB() {
            std::cout <<"Name: " << getName()  << ", age: " << getAge() << ", ";
            std::cout << "Breed: " << breed << std::endl;
        }
    
};

class Cat: public Animal {
    
 };



int main() {
    Animal ani;
    Dog dog1;
    Cat cat1;
    // ani.set("Spot", 2);
    // ani.print();

    dog1.set("Max", 3, "Labrador");
    //dog1.setBreed("Labrador");
    // dog1.print();
    dog1.printB();

    return 0;
};