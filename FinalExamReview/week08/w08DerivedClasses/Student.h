#include <iostream>

using namespace std;

//Student is a kind of Person


namespace seneca {
    const int NC = 30;
    const int NG = 20;

    class Person {
        //base class
        char* name{};
    public:
        Person();
        Person(const char* n);
        ~Person();

        virtual void displayName(std::ostream& os) const;
        virtual void displayName(std::ostream& os, const char* msg) const;
    };
    std::istream& operator>> (std::istream& is, Person& p);
    std::ostream& operator<<(std::ostream& os, const Person& p);

    class Student : public Person { // derived class //  Student is a kind of person
        int stuNo{};
        float* grade{};    // [NG]
        int ng{};
    public:
        Student();
        Student(const char* n, int stId, const float* grd, int numGrad);
        ~Student();

        void displayName(std::ostream& os)const override; // to be ploymorphic

        using Person::displayName; // exposing an overloaded member func
    };
    std::istream& operator>> (std::istream& is, Student& s);
    std::ostream& operator<<(std::ostream& os,  const Student& s);

    class Instructor :  public Person {
    public:
        using Person::Person; // inheriting the base class constructor 
        // no members in Instructor to initalize, just base class members

    };




}