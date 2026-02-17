#include <iostream>

using namespace std;

#define CAP 32
// +,-,*,/, %, [indexing], .. operators that can be overloaded

//video 1
// incrementing(++), decrementing(--)
// ++, --
class Marks {

    float m_marks [CAP]; //point to  dynamic array
    int m_capacity;
    int m_size;
    public:
        Marks(){ // default constructor
            m_size = 0;
            m_capacity = CAP;
        }
        Marks(int p_size, const float* p_marks) {
            m_capacity = CAP; // sets cap to 32
            if (p_size > 0 && p_marks != nullptr) {
                m_size = p_size <=m_capacity?p_size:m_capacity; // size will be 32 or smaller
                for (int i =0; i<m_size; i++){
                    m_marks[i] = p_marks[i];
                }
            } 
            else {
                m_size = 0;
            }
            
        }

       Marks& operator++(){
            for (int i=0; i<m_size; i++) {
                m_marks[i] +=1; // 99.1 -> 100.1
                m_marks[i] = m_marks[i] > 100?100:m_marks[i];
            }
            return *this;
        }


        void display()  const {
                if (m_size > 0){
                    cout << "Marks: ";
                    for (int i =0; i<m_size; i++){
                        cout << m_marks[i] << (i==m_size-1?'.':',');
                    } 
                }else {
                    cout << "invalid object";
                }
                cout <<endl;

            }
};










int main (void) {  
    float marks [] ={55.55,66.66,77.77,99.8}; //object array
    Marks mks (4,marks);
    mks.display();
    //++mks;
    

    //mks++;
    (++mks).display();
    int x=5;
    cout << ++x <<endl;
    return 0;
}