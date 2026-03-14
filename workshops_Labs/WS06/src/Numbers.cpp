/* -----------------------------------------------------------
Workshop 06
Module: Numbers
Filename: Numbers.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2025/03/10 Opened File, read instructions, created the required methods, functions
V0.9    2025/01/13 Ran tests, debugged, Works, added citation on the top
V1.0    2025/01/13 Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Numbers.h"
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace seneca{

    // Numbers::Numbers(){
    //     setEmpty();
    //     m_isOriginal = false;
    // }

    // Numbers::Numbers(const char* filename) {
    //     setEmpty();
    //     m_isOriginal = true;
    //     setFilename(filename);
    //     m_numCount = numberCount();
    //     if (m_numCount == 0 || !load())
    //     {
    //         delete[] m_numbers;
    //         delete[] m_filename;
    //         setEmpty();
    //         m_isOriginal = false;
    //     }
    //     else
    //     {
    //         sort();
    //     }
    // }

    Numbers::~Numbers(){
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }
    //copy constructor
     Numbers::Numbers(const Numbers& other) {
      setEmpty(); // put object in safe empty state 
      m_isOriginal = false; // mark obj as not origanal 
      
      

      if (!other.isEmpty()) {
         m_numCount = other.m_numCount;
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = other.m_numbers[i];
         }
      }
   }
    // copy assignment operator
    Numbers& Numbers::operator=(const Numbers& other) {
      if (this != &other) { //1. avoids self - assignment
         delete[] m_numbers; // 2.delete current data
         m_numbers = nullptr;
        
         m_isOriginal = false;
         m_filename = nullptr;

         if (!other.isEmpty()) { // 3. only copy if other has data
            m_numCount = other.m_numCount;

            m_numbers = new double[m_numCount]; // 4. allocate new memory 
            for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = other.m_numbers[i]; // 5. deep copy values
            }
         } else {
            m_numCount = 0;
         }
      }

      return *this; // 6. return current object
   }

//     bool Numbers::isEmpty() const {
//       return m_numbers == nullptr;
//    }

//     void Numbers::setEmpty() {
//       m_numbers = nullptr;
//       m_filename = nullptr;
//       m_numCount = 0;
//    }

//     void Numbers::setFilename(const char* filename) {
//       delete[] m_filename;
//       m_filename = new char[strlen(filename) + 1];
//       strcpy(m_filename, filename);
//    }

//    void Numbers::sort() {
//       int i, j;
//       double temp;
//       for (i = m_numCount - 1; i > 0; i--) {
//          for (j = 0; j < i; j++) {
//             if (m_numbers[j] > m_numbers[j + 1]) {
//                temp = m_numbers[j];
//                m_numbers[j] = m_numbers[j + 1];
//                m_numbers[j + 1] = temp;
//             }
//          }
//       }
//    }

//    double Numbers::average() const {
//       double aver = 0.0;
//       if (!isEmpty()) {
//          for (int i = 0; i < m_numCount; i++)
//             aver += m_numbers[i];
//          aver = aver / m_numCount;
//       }
//       return aver;
//    }
//    double Numbers::min() const {
//       double minVal = 0.0;
//       if (!isEmpty()) {
//          minVal = m_numbers[0];
//          for (int i = 1; i < m_numCount; i++)
//             if (minVal > m_numbers[i]) minVal = m_numbers[i];
//       }
//       return minVal;
//    }
//    double Numbers::max() const {
//       double maxVal = 0.0;
//       if (!isEmpty()) {
//          maxVal = m_numbers[0];
//          for (int i = 1; i < m_numCount; i++)
//             if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
//       }
//       return maxVal;
//    }

    int Numbers::numberCount() const {
      int count = 0;
       
      if(m_filename) {
         ifstream file(m_filename);
         if (file.is_open()) {
            char ch;

            //Read Character by charcter by char
            while (file.get(ch)){
               if (ch == '\n'){
                  count++;
               }
            }
         }
      }
       return count;
   }

    bool Numbers::load() {
      bool ok = false;
      if (m_filename) {
         m_numCount = numberCount();
         if (m_numCount > 0) {
            // Allocate memory for the numbers
             m_numbers = new double[m_numCount];
             ifstream file (m_filename);
             if (file.is_open()) {
               int i = 0;
               double value;
               //Read doubles untill array is filled
               while (file >> value) {
                  m_numbers[i++] = value;

                  //Only increment i if reading is successfull
                  if (i== m_numCount) {
                     break;
                  }
               }
               if (i== m_numCount){
                  ok = true;
               } else {
                  delete[] m_numbers;
                  m_numbers = nullptr;
                  m_numCount =0;

               }


             }

         }
      }

      return ok;
   }

    void Numbers::save() const {
      if (m_isOriginal && !isEmpty()) {
         ofstream file(m_filename);
         for (int i = 0; i < m_numCount; i++) {
            file << m_numbers[i] << endl;
         }
      }
   }

    Numbers& Numbers::operator+=(double value) {
      if (!isEmpty()) {
         double* temp = new double[m_numCount + 1];

         for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
         }

         m_numCount++;
         temp[m_numCount - 1] = value;

         delete[] m_numbers;
         m_numbers = temp;

         sort();
      }
      return *this;
   }

      ostream& Numbers::display(ostream& ostr) const {
      ostr.setf(ios::fixed);
      ostr.precision(2);

      if (isEmpty()) {
         ostr << "Empty list";
      } else {
         ostr << "=========================\n";
         if (m_isOriginal) {
            ostr << m_filename << '\n';
         } else {
            ostr << "*** COPY ***\n";
         }

         for (int i = 0; i < m_numCount; i++) {
            ostr << m_numbers[i];
            if (i != m_numCount - 1) {
               ostr << ", ";
            }
         }

         ostr << '\n';
         ostr << "-------------------------\n";
         ostr << "Total of " << m_numCount << " number(s)\n";
         ostr << "Largest number:  " << max() << '\n';
         ostr << "Smallest number: " << min() << '\n';
         ostr << "Average:         " << average() << '\n';
         ostr << "=========================";
      }

      return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
      return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N) {
      double value;
      istr >> value;
      if (istr) {
         N += value;
      }
      return istr;
   }

}