/* -----------------------------------------------------------
Workshop 02
Module: dma
Filename: dma.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 127
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/?/?  Completing whatever
V0.8    2025/?/?  Debugged DMA
V0.9    2025/?/?  Asked prof for help for XYZ
V1.0    2025/?/?  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
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