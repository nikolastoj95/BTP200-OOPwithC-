#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::aloCopy (const char* name) {
      deallocate();
      int len = strlen(name);
      m_name = new char[len+1];
      strcpy(m_name, name);
   }

   void CC::deallocate(){
      delete [] m_name;
      m_name = nullptr;
   }

   void CC::set() {
      deallocate(); // cc name dynamic char[]
      m_ccv=0;
      m_expMonth =0;
      m_expYear =0;
      m_ccNumber = 0ull;
   }

   bool CC::isEmpty() const {
      return m_name == nullptr;
   }

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      bool ok = true;

      // name: not null, and >2 chars
      if (name == nullptr || strlen(name) <= 2) {
         ok = false;
      }

      if (cardNo < 4000000000000000ull || cardNo >4099999999999999ull  ) {
         ok = false;
      }

      if (cvv < 100 || cvv > 999) {
         ok = false;
      }

      if (expMon < 1 || expMon > 12) {
         ok = false;
      }
      if (expYear < 24 || expYear > 32) {
         ok = false;
      }

      return ok;


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
      set(); // safe empty state first

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