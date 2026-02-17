#include <iostream>

using namespace std;

#define CAP 32
// +,-,*,/, %, [indexing], .. operators that can be overloaded

//video 1
// incrementing(++), decrementing(--)
// ++, -- 
// 

class Marks {

    float m_marks [CAP]; //point to  dynamic array
    int m_capacity; // size of the array 32 MAX -- fixed size array
    int m_size; // less than or equal to capacity -- actual size of the array
    public:
        Marks(){ // default constructor
            m_size = 0;
            m_capacity = CAP; 
        }
        // 2 arguments constructor
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

    //    Marks& operator++(){
    //     // pre increment
    //     // 99.1 -> 100.1
    //         for (int i=0; i<m_size; i++) {
    //             m_marks[i] +=1; // 99.1 -> 100.1
    //             m_marks[i] = m_marks[i] > 100?100:m_marks[i];
    //         }
    //         return *this;
    //     }
        // pre incremate or prefix ++ operator ++mks
        Marks& operator++(){
            //code and logic here
            // values in array by 1 increase
            for (int i = 0; i< m_size; i++) {
                m_marks[i] += 1; // 99.1 -> 100.1  do not want more than 100 limit to 100
                m_marks[i] = m_marks[i]> 100 ? 100 : m_marks[i];
            }
            return *this;
        }

        //post- increment operator  mks++
        Marks operator++(int) {
            Marks temp = *this; // copy current object to temp object
            //call above ++ function in here
            ++(*this);

            return temp;

        }

         // pre decremate or prefix -- operator --mks
        Marks& operator--(){
            //code and logic here
            // values in array by 1 increase
            for (int i = 0; i< m_size; i++) {
                m_marks[i] -= 1; // 99.1 -> 100.1  do not want more than 100 limit to 100
                m_marks[i] = m_marks[i]< 0 ? 0 : m_marks[i];
            }
            return *this;
        }

        //post- dencrement operator  mks--
        Marks operator--(int) {
            Marks temp = *this; // copy current object to temp object
            //call above ++ function in here
            --(*this);

            return temp;

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
    float marks [] ={55.55,66.66,77.77}; //object array
    Marks mks (3,marks);
    mks.display();
    //++mks; // pre increment // increment before  object
    // mks++;

    (++mks).display(); // operator function needs to return object return * this, Marks& 
    //mks.display();
    // 3 times
    cout << "------" << endl;
    mks++; // post incrumate
    //mks.display();

    (mks++).display();
    mks.display();

    //2 times 
    // int x = 5;

    // cout << ++x << endl;
    // int y = 6+ ++x;
    // ++ (++x);
    // cout << y<<endl;
    (--mks).display(); // preincremate
    (mks--).display(); // post increment
    mks.display();

    
    

    //mks++;
    // (++mks).display();
    // int x=5;
    // cout << ++x <<endl;
    return 0;
}