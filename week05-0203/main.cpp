#include <iostream>

using namespace std;

#define CAP 32
// +,-,*,/, %, [indexing], .. operators that can be overloaded

//video 1
// incrementing(++), decrementing(--)
// ++, -- 
// 

//video part 2  addition (+)m subtraction (-), multiplication (*), division(/), remainder (%)
// +,-,*,/,%
// + - for addition or summation
// - for subtraction
// *
// /
// %
//

//video part 3 subtrction -


class Marks {

    float m_marks [CAP]; //point to  static array
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
                // can not set p_marks to nulptr cause it is static
            }
            
        }

        // pre incremate or prefix ++ operator ++mks
        /*Marks& operator++(){
            //code and logic here
            // values in array by 1 increase
            for (int i = 0; i< m_size; i++) {
                m_marks[i] += 1; // 99.1 -> 100.1  do not want more than 100 limit to 100
                m_marks[i] = m_marks[i]> 100 ? 100 : m_marks[i];
            }
            return *this;
        }*/

        //post- increment operator  mks++
        /*Marks operator++(int) {
            Marks temp = *this; // copy current object to temp object
            //call above ++ function in here
            ++(*this);

            return temp;

        }*/

         // pre decremate or prefix -- operator --mks
        // Marks& operator--(){
        //     //code and logic here
        //     // values in array by 1 increase
        //     for (int i = 0; i< m_size; i++) {
        //         m_marks[i] -= 1; // 99.1 -> 100.1  do not want more than 100 limit to 100
        //         m_marks[i] = m_marks[i]< 0 ? 0 : m_marks[i];
        //     }
        //     return *this;
        // }

        //post- dencrement operator  mks--
        // Marks operator--(int) {
        //     Marks temp = *this; // copy current object to temp object
        //     //call above ++ function in here
        //     --(*this);

        //     return temp;

        // }

        //overloading + operator
        // return by object value 
       Marks operator+(const Marks& mks) const { // query function
            Marks temp= *this; // copying current object to temp one
            int tsize = temp.m_size;
            for (int i = 0; i< mks.m_size &&  (tsize +1) < CAP; i++) {
               temp.m_marks[tsize+i] = mks.m_marks[i];
               temp.m_size++;

            }
            return temp;

        }

         Marks operator+(float val) const { 
            Marks temp= *this; 
            int tsize = temp.m_size;
            if (tsize < m_capacity -1) {
                
                temp.m_marks[tsize] = val;
                temp.m_size++;
            }
            return temp;
        }

        // add by 5 each marks elements 
        Marks operator+(int val) const { 
            Marks temp= *this; 
           for (int i = 0; i<temp.m_size; i++) {
                temp.m_marks[i] += val;

           }
            return temp;
        }
        // overloading - operator
         Marks operator-(const Marks& mks) const {
            Marks temp = *this;
            for (int i = 0; i< temp.m_size ; i++) {
                temp = temp - mks.m_marks[i]; // it invokes bottom function
            }
            return temp;
         }

          Marks operator-(int val) const {
            Marks temp = *this;
            for (int i = 0; i< temp.m_size ; i++) {
                temp.m_marks[i] -= val;  // might go below 0
                temp.m_marks[i]  = temp.m_marks[i] < 0 ? 0 : temp.m_marks[i];
            }
            return temp;
         }


        // overloading - operator
        // remove a float value from second one 
        Marks operator-(float val) const {
            Marks temp = *this; // create temp obj by copy current obj
            int i ;
            bool exit = false;
            for (i =0; i< temp.m_size && !exit ;i++) {
                if (temp.m_marks[i] == val) {
                    exit = true; // when match happens
                }
            }
            i--;
            if (exit == true) {
                for (int j = i; j<temp.m_size-1; j++) {
                    temp.m_marks[j] = temp.m_marks[j+1];
                }

                temp.m_size--;
            }
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
    float marks1 [] ={55.55,88.88,77.77}; //object array
    float marks2 [] ={88.88, 55.55};
    Marks mks1 (3,marks1),
          mks2(2,marks2);
    mks1.display();
    mks2.display();

    //Marks mks = mks1 + mks2;  // concatenate marks in two object  1st vers
    //Marks mks = mks1 + 88.88f;  // append 88.8 to the marks array  2nd vers
    //Marks mks = mks1 + 5; //5 will be added to all marks in array // 3rd vers
    
    //Marks mks = mks1 - mks2;  // mks1 - whats in mks2  and mks1 //  remove marks from mks1 that are in mks2
    //Marks mks = mks1 - 66.66f;  // remove 88.8 from the mks1 if it exsits 2nd vers
    Marks mks = mks1 - 5; // 5 will be subtracted from all marks in array 
    
    
    // operation will concat two object

    mks.display();


    //++mks; // pre increment // increment before  object
    // mks++;

    //(++mks).display(); // operator function needs to return object return * this, Marks& 
    //mks.display();
    // 3 times
    // cout << "------" << endl;
    // mks++; // post incrumate
    //mks.display();

    // (mks++).display();
    // mks.display();

    //2 times 
    // int x = 5;

    // cout << ++x << endl;
    // int y = 6+ ++x;
    // ++ (++x);
    // cout << y<<endl;
    // (--mks).display(); // preincremate
    // (mks--).display(); // post increment
    // mks.display();

    
    

    //mks++;
    // (++mks).display();
    // int x=5;
    // cout << ++x <<endl;
    return 0;
}