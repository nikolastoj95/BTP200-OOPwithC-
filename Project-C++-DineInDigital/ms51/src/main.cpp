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