/*Final Project Milestone 4: 
Module: Ordering
Filename: Ordering.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/05  Read requirments, added function definations for Header file ordering class
2026/04/05  Read requirments, added logic to Ordering constructors, list/ordering methods, print/rest bills 
2024/04/06  tested, debugged, ran
2024/04/06  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    void Ordering::bill_Title_Print(std::ostream& os) const {
        os << "Bill # " << setw(3) << setfill('0') << m_billSeriNum 
            << " =============================\n";
            os<< setfill(' ');
    }

    void Ordering::printTotals(std::ostream& os, double total ) const {
        double tax = total * Tax;
        double grandTot = tax + total;

        os << fixed << setprecision(2);
        os <<right;

        os <<  "                     Total:" << right << setw(13) << total << endl;
        os << "                     Tax:"      << right << setw(15) << tax << endl;
        os <<  "                     Total+Tax:"  <<  right << setw(9) << grandTot << endl;

        os << "========================================" << endl;
    }



    size_t Ordering::countRecords(const char* file) const {
        size_t counter = 0; // set new line counter to 0
        ifstream fin(file); // open file
        char ch{};
        while (fin.get(ch)){
            //read one character
            if (ch =='\n'){
                //if the file is not in failure state and character is a newline
                counter++; //add one to the newline counter
            }
        } // end while
        return counter; // return the newline counter
    }

    Ordering::Ordering(const char* drinkFile, const char* foodFile) 
        : m_foodCount(0),
          m_drinkCount(0),
          m_billableCount(0),
          m_billSeriNum(1),
          m_foodArr(nullptr),
          m_drinkArr(nullptr)
    {
        // 1. Count Records in files
        size_t drinkRecs = countRecords(drinkFile); // 3 drinks 0,1,2
        size_t foodRecs = countRecords(foodFile);


        // 2. Open files 
        ifstream dfile(drinkFile);
        ifstream ffile(foodFile);

        if (!dfile || !ffile || drinkRecs ==0 || foodRecs == 0) {
            return;
        }

        //3. Dynamic memory Allocation
        m_drinkArr = new Drink[drinkRecs]; // Drink[3] // holds size of 3 drinks
        m_foodArr = new Food [foodRecs];



        size_t dCount = 0;
        // while we still have space AND the read operation is successfull 
        while (dCount < drinkRecs && m_drinkArr[dCount].read(dfile)) {
            dCount++;
            // reading each element from file
        }

        size_t fCount = 0;
        // while we still have space AND the read operation is successfull 
        while (fCount < foodRecs && m_foodArr[fCount].read(ffile)) {
            fCount++;
            // reading each element from file
        }

        // if number of read records does not match number of records in file
            // revert operation, delete food, drink arrays, set to nulptr
        if (dCount != drinkRecs || fCount != foodRecs) {
            delete[] m_drinkArr;
            delete[] m_foodArr;
            m_drinkArr = nullptr;
            m_foodArr = nullptr;
        } else {
            //set the attributes  food count and drink count to the  num of records read
            m_foodCount = fCount; // 8
            m_drinkCount = dCount; // 3 

        }
    };

     Ordering::~Ordering() {

       delete [] m_drinkArr;
       delete [] m_foodArr;
       for ( unsigned int i = 0 ;  i< m_billableCount; i++ ){
          delete m_billItems[i];
       }
     }

      Ordering:: operator bool() const {
        return m_drinkArr != nullptr && m_foodArr != nullptr;
     }

     size_t Ordering::noOfBillItems() const {
        return m_billableCount;   
     }

    bool Ordering::hasUnsavedBill() const {
        return  m_billableCount > 0;
    }

    // list food, list drink

    void Ordering::listFoods() const {

        cout << "List Of Avaiable Meals\n";
        cout << "========================================\n";
        for (unsigned int i = 0;  i < m_foodCount; i++ ){
            m_foodArr[i].print() << "\n";
        }
        cout << "========================================\n";
    }

    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks\n";
        cout << "========================================\n";
        for (unsigned int i = 0;  i < m_drinkCount; i++ ){
            m_drinkArr[i].print() << "\n";
        }
        cout << "========================================\n";
    }

    void Ordering::orderFood(){
        Menu m ("Food Menu", "Back to Order", 2);
        
        for (unsigned int i = 0; i <m_foodCount; i++){
            m <<  (const char*) m_foodArr[i]; //(const char*)
        }

        size_t sel = cout <<m; // cals select()

        if (sel == 0 ) return;
        // if selection is not 0

        if (m_billableCount < MaximumNumberOfBillItems) {
            // creates dynamic copy of selected food item 
            Food* f = new Food (m_foodArr[sel -1]); 
            if ( f->order()) {
                // assigns the select food item to next available element in Bill items increments by 1 the bill count
                m_billItems[m_billableCount++] = f; 
            } else {
                delete f;
            }

        }
    }
    void Ordering::orderDrink() {
        Menu m ("Drink Menu", "Back to Order", 2);

        for (unsigned int i = 0 ; i< m_drinkCount; i ++){
            m<< (const char*) m_drinkArr[i];
        }

        size_t sel = cout << m; // calls select()

        if (sel == 0) return;

        if (m_billableCount < MaximumNumberOfBillItems) {
            Drink* d = new Drink (m_drinkArr[sel -1]);
            if (d -> order()) {
                m_billItems[m_billableCount++] = d;
            } else {
                delete d;
            }
        }
    }

    void Ordering::printBill(std::ostream& os) const {
        double total = 0.0;

        // print the bill title
        bill_Title_Print(os);

        //2. Print each bill item and acculmlate total
        for (unsigned int i =0 ; i< m_billableCount; i++ ){
            m_billItems[i]->print(os) << "\n";
            total += m_billItems[i]->price();
        }

        //3. Print Totals

        printTotals(os,total);

    }

    void Ordering::resetBill(){
        // 1. create file name

        char filename[50]{};
        ut.makeBillFileName(filename, m_billSeriNum);

        //2. Open file

        ofstream fout(filename);

        //3. print bill into file

        printBill(fout);

        //4. Display Message

        cout << "Saved bill number " << m_billSeriNum << "\n";
        cout << "Starting bill number " << (m_billSeriNum +1) << "\n";

        //5. Delete dynamically created bill items

        for (unsigned int i =0 ; i<m_billableCount; i++){
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }

        //6. Increments bill number by one

        m_billSeriNum ++;

        // 7. Resets num of bill items to zero

        m_billableCount = 0;
 
    }








    

};