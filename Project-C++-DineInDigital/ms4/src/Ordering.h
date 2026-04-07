/*Final Project Milestone 4: 
Module: Ordering
Filename: Ordering.h
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/02/25  Read requirments, added function signtures for Header file Billable class abstract class with rule of 3 implemented
2024/03/20  tested, debugged, ran
2024/03/21  checked and done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include <iostream>
#include "constants.h"
#include "Food.h"
#include "Drink.h"

using namespace std;

namespace seneca {

    class Ordering {
        //attributes
        unsigned int m_foodCount{};
        unsigned int m_drinkCount{};
        unsigned int m_billableCount{};
        unsigned int m_billSeriNum{};

        Food* m_foodArr{};
        Drink* m_drinkArr{};
        Billable* m_billItems[MaximumNumberOfBillItems]{};


        void bill_Title_Print(std::ostream& os) const;

        void printTotals(std::ostream& os, double total ) const;

        size_t countRecords(const char* file) const;
    public:

        Ordering(const char* drinkFile, const char* foodFile);
        ~Ordering();
        operator bool() const;

        size_t noOfBillItems() const;

        bool hasUnsavedBill() const;

        void listFoods() const;

        void listDrinks() const;

        void orderFood();
        void orderDrink();

        void printBill(std::ostream& os) const;
        void resetBill();
    };


}
#endif