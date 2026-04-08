/* 
Final Project Milestone 51: 
Module: Main
Filename: Main.cpp
Version 1.0
Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2026/04/06  Include Modules need for main like Menu.h, Ordering.h, iostream, fstream
2024/04/06  Created object for Ordering class to bring in two data files drink, food, so it can be listed 
2024/04/07  Created a Menu Object to display Main Menu, and ordering menu, calling  ordering food, drinks too
2024/04/07  Tested, Debuged, Cleaned Up, Ran
2024/04/08  Checked and Done
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;


int main() {

    size_t selection{};
    size_t orderSelection{};
    size_t confirm{};

    
    Menu homeMenu("Seneca Restaurant", "End Program");
    homeMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    Menu orderMenu("Order Menu", "Back to main menu", 1);
    orderMenu << "Food" << "Drink";

    Menu exitConfrim ("You have bills that are not saved. Are you sure you want to exit?", "No");
    exitConfrim << "Yes";
    

    Ordering ord("drinks.csv", "foods.csv");
    if (!ord) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    };

    do
    {

        switch (selection = homeMenu.select())
        {
        case 0: // Exit Program
            if (ord.hasUnsavedBill())
            {
                confirm = exitConfrim.select();
                if (confirm == 1)
                {                                // YES
                    cout << "Good Bye!" << endl; // leaves
                }
                else
                { // selecting 0 or Not //to stay
                    selection = 1;
                }
            }
            else
            {
                cout << "Good Bye!" << endl;
            }

            break;
        case 1: // Order
            do
            {
                switch (orderSelection = orderMenu.select())
                {
                case 1:
                    // food ordering
                    ord.orderFood();
                    break;
                case 2:
                    // drink ordering
                    ord.orderDrink();
                    break;
                }
            } while (orderSelection);
            break;
        case 2://Print Bill to Console
            if (ord.noOfBillItems() > 0)
            {
                ord.printBill(cout);
            }
            else
            {
                cout << "No Items in Bill!" << endl;
            }
            break;
        case 3: // Start New Bill
            if (ord.hasUnsavedBill())
            {
                ord.resetBill();
            }
            else
            {
                cout << "No active bill to save!" << endl;
            }
            break;
        case 4: // List Foods
            ord.listFoods();
            break;
        case 5: // List Drinks
            ord.listDrinks();
            break;
        default: // Never Should Reach Here Cause of Validation
            cout << "Should not happen!" << endl;
            break;
        }
    } while (selection); // keeps looping if selection=1 stays

    return 0;
}