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
    T*& dynaCopy (T*& des, const T* src,  int size){
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




    /*
     char* Utils::alocpy(char*& des, const char* src) const {
      delete[] des; // Free any existing memory
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1]; // Allocate memory for copy
         strcpy(des, src);                // Copy content
      }
      return des;
   }*/


}



#endif