// schoolLunchOrderSystem_LaraKeith.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//  ===== THIS CODE HOLDS LARA AND KEITH'S CODE FOR OUR SCHOOL LUNCH ORDER SYSTEM =====

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

// ===== vv Write stuctures here vv =====
struct ParentAcc {
    string firstName;
    string lastName;
    int pinNum;
    string contactNum;

    string childName;
    int childRoomNum;

    string cardNum;
    string cardExpiry;

};

struct MenuItems {
    string itemName;
    float itemPrice;
};

struct AdminAcc {
    string firstName;
    string lastName;
    int pinNum;
};
// ===== ^^ Write stuctures here ^^ =====

// -- create underlines only --
void underLine(int x) {
    int i;

    for (i = 0; i < x; i++) {
        cout << "-";
    }
    cout << endl;
}

// ===== vv LARA CODE SECTION vv =====
void bulkDiscount() {
    cout << "\n\t\t\tBulk Discount Offers\t\t\t" << endl;
    underLine(80);

    cout << "\nItems can be ordered over different days for the children \n(including different weeks)";
    cout << "\n\n1. 15 Items Ordered = 5% off total order";
    cout << "\n2. 25 Items Ordered = 10% off total order";
    cout << "\n1. 40+ Items Ordered = 15% off total order";
}

void contactDetails() {
    cout << "\n\t\t\tContact Details\t\t\t" << endl;
    underLine(80);
    cout << "\nIf you would like to contact us regarding any queries you \nmay have you may reach us via our phone number and email \nshown below: ";
    cout << "\n\nContact Number: (04) 578 - 2364";
    cout << "\n\nEmail: schoollunchsystem@gmail.com";
    cout << "\n\nOffice Location 45 School St, Thorndon, Wellington, NZ";
    cout << "\n\nOffice Hours: 1pm - 5pm, Monday - Friday";
}

void ParentReg(ParentAcc* ptr) {
    int num;

    cout << "\n\t\t\tRegistration\t\t\t" << endl;
    underLine(80);
    cout << "\nFirst name: ";
    cin >> ptr->firstName;
    cout << "\n\nLast name: ";
    cin >> ptr->lastName;
loginpin:
    cout << "\n\nLogin Pin (This will be used as your password to login, must \nbe 4 numbers): ";
    cin >> num;
    if (num > 999 && num < 10000) {
        ptr->pinNum = num;
    }
    else {
        cout << "\n\nPlease enter a valid 4 digit number";
        goto loginpin;
    }
    cout << "\n\nContact number (no spaces): ";
    cin >> ptr->contactNum;
    cout << "\n\nChild's first name: ";
    cin >> ptr->childName;
    cout << "\n\nChild's room number: ";
    cin >> ptr->childRoomNum;
    cout << "\n\nCard Number (no spaces)";
    cin >> ptr->cardNum;
    cout << "\n\nCard Expiry Date (format as MM/YY)";
    cin >> ptr->cardExpiry;
}

void parentLogin() {

}

// ===== ^^ LARA CODE SECTION ^^ =====

// ===== vv KEITH CODE SECTION vv =====

// -- menu preview CANNOT ORDER FROM HERE (IN PROGRESS)  --
void  menuPreview() {
    struct MenuItems menu[9];
    struct MenuItems* ptrmenu = menu;

    int i;

    fstream outfile;

    outfile.open("menuItems.csv", ios::out);
    cout << "\n\t\t\Menu Preview\t\t\t" << endl;
    underLine(80);
        
    outfile << "Ham Sandwich" << ","
        << "4.50" << endl
        << "Vegetarian Sandwich" << ","
        << "5.00" << endl
        << "Chicken and Avo" << ", "
        << "6.50" << endl << endl
        << "Steak and Cheese" << ", "
        << "4.50" << endl
        << "Butter Chicken" << "-, "
        << "5.50" << endl
        << "Mushroom and Cheese" << "-, "
        << "6.50" << endl << endl
        << "Cheese" << "-, "
        << "4.50" << endl
        << "Pepperoni" << "-, "
        << "5.50" << endl
        << "Veg (GF)" << "-, "
        << "6.50" << endl;
    outfile.close();

    fstream infile;

    infile.open("menuItems.csv", ios::in);
    
    string readData;
    int itemPrice;
    
    cout << "Menu Items: \n\n";
    while (getline(infile, readData)) {
        cout << readData << endl;
    }
        
    infile.close();

    /*cout << "\n\t\t\Menu Preview\t\t\t" << endl;
    underLine(80);

    cout << "\n Sandwiches:" << endl;
    cout << "\n\tHam Sandwich              $4.50" << endl;
    cout << "\n\tVegetarian Sandwich       $5.00" << endl;
    cout << "\n\tChicken and Avo           $6.50" << endl;

    cout << "\n Pies:" << endl;
    cout << "\n\tSteak and Cheese          $4.50" << endl;
    cout << "\n\tButter Chicken            $5.50" << endl;
    cout << "\n\tMushroom and Cheese       $6.50" << endl;

    cout << "\n Pizza:" << endl;
    cout << "\n\tCheese                    $4.50" << endl;
    cout << "\n\tPepperoni                 $5.50" << endl;
    cout << "\n\tVeg (GF)                  $6.50" << endl;*/
}

// ===== ^^ KEITH CODE SECTION ^^ =====

int main()
{
    int index;
    int flag = 0;

    struct ParentAcc Parent;
    struct ParentAcc* ptrParent;

    ptrParent = &Parent;

    // --- added intro screen below V --- //
    cout << "\n\t\t\tSchool Lunch Order System\t\t\t" << endl;
    underLine(80);

    cout << "\n\tPlease make a selection from the options below:" << endl;
MenuSelect:
    cout << "\n\t1.  Preview of Menu" << endl;
    cout << "\t2.  Bulk Discount Offers" << endl;
    cout << "\t3.  School Contact Details & Location" << endl;
    cout << "\t4.  Login to your account" << endl;
    cout << "\t5.  Register a new account" << endl;

    cout << "\n  Selection: ";
    cin >> index;

    switch (index) {
    case 1:
        menuPreview();

        cout << "\n Enter 1 to return back to Main Menu: ";
        cin >> flag;

        if (flag != 1) {   //find a way to make this loop if condition is not met (IN PROGRESS)
            cout << "invalid input! Try again: ";
        }
        else {
            goto MenuSelect;
        }

        break;
    case 2:
        bulkDiscount();

        cout << "\n Enter 1 to return back to Main Menu: ";
        cin >> flag;
    redo1:
        if (flag != 1) {
            cout << "invalid input! Try again: ";
            cin >> flag;
            goto redo1;
        }
        else {
            goto MenuSelect;
        }
        break;
    case 3:
        contactDetails();

        cout << "\n Enter 1 to return back to Main Menu: ";
        cin >> flag;
    redo2:
        if (flag != 1) {
            cout << "invalid input! Try again: ";
            cin >> flag;
            goto redo2;
        }
        else {
            goto MenuSelect;
        }
        break;
    case 4:
        parentLogin();
        break;
    case 5:
        ParentReg(ptrParent);
        //Have them go to parents log in menu screen once registered as they are technically logged in
        break;
    default:
        cout << "It seems your selection was invalid, please select one of the given options: " << endl;
        goto MenuSelect;
    }


}