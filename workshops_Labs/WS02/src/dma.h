#ifndef SENECA_DMA_H
#define SENECA_DMA_H
#include "cstr.h"
namespace seneca {
    struct Samples {
        char* m_title; // Dynamically allocated title
        int* m_data; //Dynamically allocated array of ints
        int m_size; // Number of elements in m_data 
    };

    Samples* CreateSamples (const char* title);
    void add (Samples& S, const int data[], int size);
    void append (int*& data, int size, const int appendedData[], int dataSize);
    void freemem(Samples*& s);
} // namespace seneca


#endif // SENEC_ADMA_H