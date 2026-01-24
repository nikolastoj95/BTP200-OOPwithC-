#include "dma.h"
#include "cstr.h"
#include <iostream>


namespace seneca {
    Samples* CreateSamples (const char* title) {
        //1 allocate Samples on heap
        Samples* s = new Samples;

        //2 allocate title
        int len = strlen(title); // length of title string
       

        // pointer s points to Samples obj  the m_title member
        // allocated memory for this character array
        s-> m_title = new char[len+1];
       
        // moves the title src to the destination m_title
        strcpy(s->m_title, title);

        //3. init data

        s-> m_data = nullptr;
        s-> m_size = 0;
        return s;
           
    };
    void add (Samples& S, const int data[], int size){
        if (size <=0 || data == nullptr) return;

        if (S.m_data == nullptr) {
            // allocate and copy incoming values
            S.m_data = new int[size]; // allocates an array of int 
            for (int i = 0; i< size; i++) {
                S.m_data[i] = data[i];
            }
            S.m_size = size;
        } else {
            // expand existing array and append
            append(S.m_data, S.m_size, data, size);
            S.m_size += size;
        }

    };
    void append(int*& data, int size, const int appendedData[], int dataSize) {

    if (dataSize <= 0 || appendedData == nullptr) return;

    //allocate new bigger array
    int* temp = new int [size + dataSize];

    //copy old values
    for (int i =0; i< size; i ++){
        temp[i] = data [i];
    }
    //append new values
    for (int i =0; i<dataSize; i++){
        temp [size +i] = appendedData[i];
    }
    // free old array space
    delete[] data;
    //updates deleted data pointer to the newly allocated memory
    data = temp;

    // int newSize = size + dataSize;

    // // 1) allocate new bigger array
    // int* temp = new int[newSize];

    // // 2) copy old values
    // for (int i = 0; i < size; i++) {
    //     temp[i] = data[i];

    // }
    

    // // 3) append new values
    // for (int i = 0; i < dataSize; i++) {
    //     temp[size + i] = appendedData[i];
    // }

    // // 4) free old array
    // delete[] data;

    // // 5) update pointer to point at new memory
    // data = temp;
}

void freemem(Samples*& s) {
    if (s == nullptr) return;

    delete[] s->m_title;
    delete[] s->m_data;
    delete s;

    s = nullptr;
}
    // void append (int& data, int size, const int appendedData[], int dataSize){

    // };

    // void freemem(Samples*& s){

    // };


} // namespace seneca