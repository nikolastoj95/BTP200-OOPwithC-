// SOURCE FILE
//io.cpp
/* Citation and Sources...
-----------------------------------------------------------
OOP244 Workshop #1: io module SOURCE FILE
Module: io
Filename: io.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027369149
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date        Reason
V0.1    2025/01/14  Created file included header file,io.h cstr.h created namespace seneca
V0.2    2025/01/15  added functions I delcared in io.h, wrote functions 
V0.3    2025/01/16  Complied the file, Tested them got right output
V0.4    2025/01/16  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "io.h"
#include "cstr.h"

#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca{
    void read (char* name){
        cout << "name\n ";
        cin >> name;
    };
    bool read (PhoneRec& rec, FILE* fptr){
        //reads: FirstName<TAB>LastName<TAB>PhoneNumber
        return fscanf(fptr, "%s %s %lld", rec.name, rec.lastname, &rec.number) ==3;
    };

    void print (long long phoneNumber){
        long long area = phoneNumber / 10000000LL;
        long long prefix = (phoneNumber /10000LL) % 1000LL;
        long long line = phoneNumber % 10000LL;

        cout << "(" << setw(3) << setfill('0') << area << ") "
            << setw(3) << setfill('0') << prefix << "-"
            << setw(4)<< setfill('0')<< line;

        cout << setfill(' ');
    };

    void print (const PhoneRec& rec, size_t& row, const char* filter){
        bool matches = false;
         if (!filter) {
            matches = true;
         } else {
            if (strstr(rec.name, filter) || strstr(rec.lastname, filter)){
                matches = true;
            }
         }

         if (matches){
            cout << row << ": " << rec.name << " " << rec.lastname << " ";
            print (rec.number);
            cout << endl;
            row++;
         }
    }
    
    void print (PhoneRec* recPtrs[], size_t size, const char* filter) {
        size_t row = 1;
        for (size_t i =0 ; i< size; i++){
            print (*recPtrs[i],row, filter);
        }

    }
    void setPointers (PhoneRec* ptrs[], PhoneRec recs[], size_t size){
        for (size_t i = 0; i< size; i++){
            ptrs[i]= &recs[i];
        }
    }

     void sort(PhoneRec* recPtrs[], size_t size, bool byLastName) {
      for (size_t i = 0; i < size - 1; i++) {
         for (size_t j = i + 1; j < size; j++) {

            const char* a = byLastName ? recPtrs[i]->lastname : recPtrs[i]->name;
            const char* b = byLastName ? recPtrs[j]->lastname : recPtrs[j]->name;

            if (strcmp(a, b) > 0) {
               PhoneRec* tmp = recPtrs[i];
               recPtrs[i] = recPtrs[j];
               recPtrs[j] = tmp;
            }
         }
      }
   }
   
}