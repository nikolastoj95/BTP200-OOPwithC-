/* -----------------------------------------------------------
Workshop 10
Module: dynaCopy
Filename: dynaCopy.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.8    2026/04/09  Opened files, read requirments, studyed the Name module, main.cpp, Utils.cpp
V0.9    2026/04/09  Added the Function templates for functions to copy elements of one array to another and a function to print the elements of the array it is a generic type so any types can use the function
V1.0    2026/04/09 Tested, Debuged ,and Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>

using namespace std;

namespace seneca{

    template <typename T>
    T* dynaCopy (const T* src, int size ){
        T* des{};
        
        if (src) {  
            des = new T [size];
            for (int i = 0; i < size; i++) {
                des[i] = src[i];
            }
        }
       return des;  
    }

    template <typename T>
    T* dynaCopy (T*& des, const T* src,  int size){
        if (des != nullptr) {
            delete [] des; // free existing memory;
            des = nullptr;
        }

        if (src) {
            des  = new T [size];
            for (int i = 0; i < size; i++){
                des[i] = src[i];
            }
        }
        return des;
    }

    template <typename T>
    void prnArray (const T* arr, int size ) {
        for (int i = 0; i< size; i++){
            cout << arr[i]  << ((i < size -1 ) ? ", " : "\n");
        }
    }
}
#endif