// SOURCE FILE
//io.cpp
#include "io.h"
#include "cstr.h"

#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca{
    void read (char* name){
        cout << "name>\n";
        cin >> name;
    };
    bool read (PhoneRec& rec, FILE* fptr){
        //reads: FirstName<TAB>LastName<TAB>PhoneNumber
        return fscanf(fptr, "%s %s $llb", rec.name, rec.lastname, &rec.number) ==3;
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

    void print (PhoneRec* recPtrs[], size_t size, const char*)
   
}