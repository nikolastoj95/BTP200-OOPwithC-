#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca {
    struct Samples {
        char* m_title; // Dynamically allocated title
        int* m_data; //Dynamically allocated array of ints
        int m_size; // Number of elements in m_data
        
    };

} // namespace seneca


#endif // SENEC_ADMA_H