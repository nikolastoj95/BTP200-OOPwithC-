#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;

void listFoods();
void listDrinks();


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
    }

    do {
        
        switch (selection = homeMenu.select())
        {
            
        case 0:
            if (ord.hasUnsavedBill()){
                confirm = exitConfrim.select();
                if (confirm == 1) {
                    cout << "Good Bye!" << endl;
                    break;
                    
                }else {
                    
                    selection = 0; // force to continue
                }
               

            } else {
                // if no items in bill leave normally
                cout << "Good Bye!" << endl;

            break;

            }
            
        case 1:
            // cout <<"Ordering...."<<endl;
            orderSelection = orderMenu.select();
            if ( orderSelection == 1) {
                ord.orderFood();
            } else if (orderSelection == 2) {
                ord.orderDrink();
            }
            break;
        case 2:
            // cout << "Printing Bill......"<< endl;
            if (ord.noOfBillItems() >0) {
                ord.printBill(cout);
            } else {
                cout << "No Items in Bill!" << endl;
            }
            break;
        case 3:
            // cout <<"Start New Bill"<< endl;
            if (ord.hasUnsavedBill()) {
                ord.resetBill();
            } else {
                 cout << "No active bill to save!" << endl;
            }
            break;
        case 4: 
            ord.listFoods();
            break;
        case 5:
            ord.listDrinks();
            break;
        default:
        cout << "Should not happen!" <<endl;
            break;
        }
    } while (selection);


    return 0;
}

void listFoods() {
    
    // cout << "testing List all Foods for ordering from file"<< endl;
    
    // cout << "Listing Foods Test" <<endl;
    
    
    // Menu listFmenu("Seneca Resturant", "End Program");
    // appMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    // appMenu.select();
}

void listDrinks() {
    
    
}




//  cout << "Listing Drinks Test" <<endl;
//     ord.listDrinks();