#include <iostream>
//Question One 
// Resource, copy semantics , Inheritance
using namespace std;
//base Class
class Animal { 
    ///attributes 
    char* m_name{}; // dynamic array of characters
    int m_age{}; // int holding age
    char m_gender{}; // 'M' or 'F' Male or Female // character hold single char

    //using Private Member function init for common code 
    // in copy constr, copy assignment
    void init (const Animal& src ) {
        //shallow copy
        m_age = src.m_age;
        m_gender = src.m_gender;
        //allocate memory for name
        if (src.m_name !=nullptr) {
            m_name = new char [strlen(src.m_name)+1];
            // copy data from the source resouce
                // to the newly created resource
            m_name = src.m_name;
        } else {
            m_name = nullptr;
        }
    }
protected:
    // only accessable by derived classes
    char* getName()const {
        return m_name;
    }
    int getAge()const {
        return m_age;
    }
    char getGender() const {
        return m_gender;
    }

    void setName(const char* n) {
        if ( n != nullptr) {
            delete [] m_name;
            m_name = new char [strlen(n)+1];
            strcpy(m_name,n );
        } else {
            delete [] m_name;
            m_name = nullptr;
        } 
    }
    
    void setAge(int age) {
        if ( age >= 0) {
            m_age = age;
        } 
    }
    void setGender(char gender) {
        if ( gender =='M' || gender == 'F') {
            m_gender = gender;
        }   
    }
public:
    Animal () {
        std::cout << "BClass Def Constr" << std::endl;
        m_name = nullptr;
        m_age = 0;
        m_gender = '\0';
    }
    Animal (const char* n, int age, char gender) {
        std::cout << "BClass ArgConstr" << std::endl;
        if (n != nullptr && age >= 0  && gender != '\0')  {
            m_name = new char [strlen(n)+1];
            strcpy(m_name, n);
            m_age= age;
            if (gender == 'M' || gender == 'F') {
                m_gender = gender;
            } 
        } else {
            m_name = nullptr;
            *this = Animal();
        }
    }
    //copy constructor
    Animal(const Animal& src) {
        // //shallow copy
        // m_age = src.m_age;
        // m_gender = src.m_gender;
        // //allocate memory for name
        // if (src.m_name !=nullptr) {
        //     m_name = new char [strlen(src.m_name)+1];
        //     // copy data from the source resouce
        //         // to the newly created resource
        //     m_name = src.m_name;
        // } else {
        //     m_name = nullptr;
        // }
        //init (src); // calls private init function
        //using direct call
        // copy assingment optertar will allocate, deallocate m_name
        m_name = nullptr; // sets m_name of this object  to nullptr 
        *this = src; // calls copy-assignment operator
    }

    //copy assignment operator
    Animal& operator=(const Animal& src){
        // using direct call
        //copy assignment operater does all logic
        //1. check for self assignment 
        // check address of current object vs. address of the src object
        if (this != &src ) {
            //2. deallocated any pervoiud allocated memory
            delete [] m_name;

            //init(src); // calls private member function init

            //3. shallow copy all non resource instance variabls
            m_age = src.m_age;
            m_gender = src.m_gender;

            if (src.m_name != nullptr) {
                
                 // 4. Allocate new memory for resource of current obj
                m_name = new char [strlen(src.m_name)+1];
                //5. deep copy name data
                m_name = src.m_name;
            } else {
                m_name = nullptr;
            }

           
        }
        return *this;// return pointer to current object

    }
    void display ()  const{
        std::cout << "Horse Name: " << m_name << "\n";
        cout << "Age: "<< m_age << "\n";
        cout << "Gender:"<< m_gender<< "\n";
    }
    ~Animal () {
        std::cout << "BClass Destr" << std::endl;
        delete [] m_name;
        m_name = nullptr;
    }
    
};
//derived class Horse
class Horse : public Animal {
    //attributes
    // both require deep copy
    char* m_breed; // C style null terminated string // dynamic memory space
    int* m_participation; // dynamic array  of ints [ num of time per_year, times year before, times 2nd year before, ..]
    int m_years; // int of years participated
public:
    Horse() : Animal (){
        std::cout << "DerClass Def Constr" << std::endl;
        m_breed = nullptr;
        m_participation = nullptr;
        m_years = 0;
    }

    void set (const char* n, int age, char gender, const char* breed, const int* particip , int years) {
        setName(n);
        setAge(age);
        setGender(gender);

        if (breed != nullptr) {
            delete []m_breed;
            m_breed = new char [strlen(breed)+1];
            strcpy(m_breed, breed); 
        } else {
            delete []m_breed;
            m_breed = nullptr;
        }
        if (particip != nullptr && years>0){
            m_years = years;
            delete [] m_participation;
            m_participation = new int [m_years];
            for (int i = 0 ; i< m_years; i++){
                m_participation[i]= particip[i];
            }
        } else {
            delete [] m_participation;
            m_participation = nullptr;
            m_years =0;
        }

    }

    // custom constr
    Horse (const char* n, int age, char gender, const char* breed, const int* particip , int years ) : Animal (n, age, gender) {
        std::cout << "Devclass Cus Constr" << std::endl;
        if (breed != nullptr ) {
            m_breed = new char [strlen(breed)+1];
            strcpy(m_breed, breed);    
            
        } else {
            m_breed = nullptr;
        }

        if (particip != nullptr && years >0) {
            m_years = years;
            m_participation = new int [m_years];

            for (int i = 0 ; i< m_years; i++) {
                m_participation[i] = particip[i];
            }

        } else {
            m_participation = nullptr;
            m_years = 0;
        }
        
    }



    //copy constructor

    Horse (const Horse& src) : Animal(src) { // Horse copy constructor  calling base class one too
        m_breed = nullptr;
        m_participation = nullptr;
        *this = src;
    }
    //copy assignment operator
    Horse& operator= (const Horse& src) {
        // 1. check for self assignment
        if (this != &src) {
            Animal::operator=(src); // calls base class copy assignment
            //2. deallocate any perivous allocated memory
            delete [] m_breed;
            delete[] m_participation;
            m_breed = nullptr;
            m_participation = nullptr;

            //3. shallow copy of non resource instance var
            m_years = src.m_years;

            if (src.m_breed != nullptr) {
                // allocate memeory of resources of curr obj
                m_breed = new char [strlen(src.m_breed)+1];
                strcpy(m_breed, src.m_breed);
            } else {
                m_breed = nullptr;
            }

            if (src.m_participation != nullptr && src.m_years >=0 ) {
                
                m_participation =  new int [m_years];       
            
                for (int i =0; i < src.m_years; i++){
                    m_participation[i] = src.m_participation[i];
                }
            } else { 
                m_participation = nullptr; 
            }
        }
        return *this;
    }

    void display ()  const {
        Animal::display(); // calls Animal base class display

        cout << "Breed: " << m_breed << ' ' << "\n" << "Participation:";
        
        for (int i = 0 ; i < m_years ; i ++ ){
            cout << m_participation[i] << ( i < m_years -1 ?  "," : ""  ) ;
        }
        cout << endl;


    }

    //destructor
    ~Horse(){
        delete [] m_breed; // array of chars
        delete [] m_participation; // array of ints 
        m_breed = nullptr;
        m_participation = nullptr;
        m_years = 0;
    }

};

int main () {
    Animal a1;
    // Animal a("Jack", 34, 'M');
    Horse h;
    int particip [] = {5,3,1};
    
    h.set("Jack", 4, 'M', "Mustang", particip, 3 );
    h.display();
    return 0;
}