#include <iostream>
// Week 04 Constructors (Default or Arg) and Destructors 

using namespace std;

struct Marks{
    float* marks; // to point to dynamic array
    int size;
};

// default Constructor

class Student {
        char* name; // to point to dynamic array
        int id;
        Marks marksObj;
    public:
        void set(int p_id, const char* p_name, const Marks& p_marks) {
            if (name != nullptr) {
                delete[] name; // free previously allocated memory
            }
            name = new char [strlen(p_name) + 1];
            strcpy(name, p_name);
            id = p_id;
            marksObj.size = p_marks.size;
            if (marksObj.marks != nullptr) {
                delete[] marksObj.marks; // free previously allocated memory
            } 
            marksObj.marks = new float [p_marks.size];
            for (int i =0; i< marksObj.size; i++) {
                marksObj.marks[i] = p_marks.marks[i];
            }
        };

        void display() const {
            cout << "Id: " << id <<  " Name: " << name;
            cout << ", Marks: "; 
            for (int i =0 ; i< marksObj.size; i++) {
                cout << marksObj.marks[i] << (i == marksObj.size -1 ? "." : ",");
            cout << endl;
            }
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

    Student st;

    st.display();

    st.set(1001,"Jackson", mks);

    st.display();

    // st.deAllocate();


    // std::cout << "Hello World!" << std::endl;
    return 0;
}