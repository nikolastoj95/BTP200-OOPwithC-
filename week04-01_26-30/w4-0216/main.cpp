#include <iostream>
// Week 04 Constructors (Default or Arg) and Destructors 

using namespace std;

struct Marks{
    float* marks; // to point to dynamic array
    int size;
};

// default Constructor

//custom Constructor




class Student {
        char* name; // to point to dynamic array // default nullptr
        int id; // 0 is default
        Marks marksObj; // marks object - marks array default nullptr , size - 0
    public:
        Student () { // Default Constructor
            name = nullptr;
            id =0;
            marksObj.marks = nullptr;
            marksObj.size = 0;
        }; // construcor name same as class name

        bool isDefault() {
            if (name == nullptr || id == 0) {
                return true;
            } 
            return 0;
        }

        //custom constructor
        // 3 arg constructor

        Student (int p_id, const char* p_name, const Marks& p_marks) {
            // vaildation (here usllay)

             // create object for first time no need for delete[]
            name = new char [strlen(p_name) + 1]; //allocated 
            strcpy(name, p_name);
            id = p_id;
            marksObj.size = p_marks.size;
            marksObj.marks = new float [p_marks.size]; // allocated

            for (int i =0; i< marksObj.size; i++) {
                marksObj.marks[i] = p_marks.marks[i];
            }

        }

        // 2nd custom constructor // 2arg constructor
        Student (int p_id, const char* p_name) {
            name = new char [strlen(p_name) + 1]; //allocated 
            strcpy(name, p_name);
            id = p_id;
            marksObj.size = 0;
            marksObj.marks = nullptr;

        }


        void set(int p_id, const char* p_name, const Marks& p_marks) {
            if (name != nullptr) {
                delete[] name; // free previously allocated memory
            }
            name = new char [strlen(p_name) + 1]; //allocated 

            strcpy(name, p_name);
            id = p_id;
            marksObj.size = p_marks.size;
            if (marksObj.marks != nullptr) {
                delete[] marksObj.marks; // free previously allocated memory
            } 
            marksObj.marks = new float [p_marks.size]; // allocated

            for (int i =0; i< marksObj.size; i++) {
                marksObj.marks[i] = p_marks.marks[i];
            }
        };

        void display() const {
            cout << "Id: " << id <<  " Name: " << name;
            cout << ", Marks: "; 

            if (marksObj.marks != nullptr || marksObj.size != 0) {
                for (int i =0 ; i< marksObj.size; i++) {
                    cout << marksObj.marks[i] << (i == marksObj.size -1 ? "." : ",");
                    
                }

            } else {
                cout << "N/A";
            }
            cout << endl;


           
        };

        void deAllocate () {
            delete[] name;
            delete[] marksObj.marks;

        };        

};





int main (void) {

    Marks mks; // create marks object

    mks.size =5; //setting size to 5
    mks.marks = new float[5] {44.44,55.55,66.66,77.77,88.88};

    Student st; // creates an object, invokes default constructor // sets data members to 0, nullptr

    if (!st.isDefault()) {
        st.display();
    } else {
        cout << "object data is empty"<< endl;
    }



    st.set(1001,"Jackson", mks);
    

    if (!st.isDefault()) {
        st.display();
    } else {
        cout << "object is empty" << endl;
    }

    // no need for set() or default constructor calls if doing customer constructor calls
    Student st1 (1001,"Jackson", mks); // - need to have custom constructor defined

    

     if (!st1.isDefault()) {
        st1.display();
     } else {
        cout << "obect is empty"<< endl;
        }

    

    Student st2 (2002, "Sally");

    if (!st2.isDefault()) {
        st2.display();
    } else {
        cout << "obj is empty"<< endl;
    }

    st.deAllocate();
    st1.deAllocate();
    st2.deAllocate();

    // std::cout << "Hello World!" << std::endl;
    return 0;
}