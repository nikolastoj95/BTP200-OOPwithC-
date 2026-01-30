/* -----------------------------------------------------------
Workshop 03
Module: CC
Filename: CC.cpp
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 127
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.6    2025/01/29 Opened File, read instructions two private methods with the logic  were they display with 5 args, and print number
V0.7    2025/01/29 in CC.cpp added the function desciptions logic to copy name to dynamic allocated memory, setting all the fields, valdiateing the inputs, 
V0.9    2025/01/30 added the public methods, constructor for the CC class setting all the 5 fields, displaying them, deallocating them at the end
V0.9    2025/01/30 Ran tests, debugged, Works, added citation on the top
V1.0    2025/01/30 Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::aloCopy (const char* name) {
      deallocate();
      int len = strlen(name);
      m_name = new char[len+1]; // setting a dynamic memory location for the length of name +1
      strcpy(m_name, name); // copying the proved name to the class attribute m_name
   }

   void CC::deallocate(){
      delete [] m_name; // deleteing the memory  pointed to the class attrubute m_name
      m_name = nullptr; // sets the m_name attribute to null pointer
   }

   void CC::set() {
      deallocate(); // cc name dynamic char[], sets name to nullptr
      m_ccv=0;
      m_expMonth =0;
      m_expYear =0;
      m_ccNumber = 0ull;
   }

   bool CC::isEmpty() const {
      return m_name == nullptr;
   }

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      // default is true , if all is validated
      bool ok = true;

      // name: not null, and > 2 chars
      if (name == nullptr || strlen(name) <= 2) {
         ok = false;
         // not valiated, ok is false
      }

      if (cardNo < 4000000000000000ull || cardNo >4099999999999999ull  ) {
         ok = false;
      }
      // cvv has to be a 3 digit number
      if (cvv < 100 || cvv > 999) {
         ok = false;
      }
      // expiry month has to be between 1 and 12
      if (expMon < 1 || expMon > 12) {
         ok = false;
      }
      // expiry year has to be between 24 and 32
      if (expYear < 24 || expYear > 32) {
         ok = false;
      }

      return ok;
      // if all passes return the true ok
   }



   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      set(); // set to  safe empty state first

      if (validate(cc_name,cc_no, cvv, expMon, expYear )){
         // if true
         //set the fields
         aloCopy(cc_name);
         m_ccNumber = cc_no;
         m_ccv = cvv;
         m_expMonth = expMon;
         m_expYear = expYear;

      }
      // if false it remains empty fields
   }

    void CC::display() const {
      if (isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;

      } else {
         //if not in safe empty state display the object
         // using display (private method)
         display(m_name, m_ccNumber, m_expYear, m_expMonth, m_ccv);
      }
      
   }
   // non arg constructor
   CC::CC() {
      set();
      // non arg constructor, Initializes the object to a safe empty state.
   }
   // 5 arg constructor
   CC:: CC(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      set(); // safe empty state
      if (validate(cc_name, cc_no, cvv, expMon, expYear )) {
         // if true
         //set the fields
         aloCopy(cc_name);
         m_ccNumber = cc_no;
         m_ccv = cvv;
         m_expMonth = expMon;
         m_expYear = expYear;

      }
      // if validate is false then keeps at empty state set()

   }
   // destructor
   // deallocated any dynamic resources belonging to the class
   // for this the cc_name only
   CC::~CC(){
      deallocate();
   }



  



}