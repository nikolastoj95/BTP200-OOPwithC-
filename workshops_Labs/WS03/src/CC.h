/* -----------------------------------------------------------
Workshop 03
Module: CC
Filename: CC.h
-----------------------------------------------------------
Author: Nikola Stojanovic
Student number: 027 369 127
Email: nstojanovic@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.6    2025/01/28 Opened File, read instructions two private methods were they display with 5 args, and print number
V0.7    2025/01/29 in CC.h added the private class attrubutes (5) and the one private method vaildate to check if the (5) inputs are right
V0.8    2025/01/30 added the public methods, constructor(args/non args), deconstructor, set()/set(with args)
V0.9    2025/01/30 Ran tests, debugged, Works, added citation on the top
V1.0    2025/01/30 Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      //private attributes
      char* m_name{}; // dynamic array
      unsigned long long m_ccNumber{};
      short m_ccv{};
      short m_expMonth{};
      short m_expYear{};

      void aloCopy (const char* name);
      void deallocate();

      /*two functions display and prnNumber came here provided*/
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      void prnNumber(unsigned long long no) const;
      /**/

      //validates the input
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear)const;

      public:

      void set();
      bool isEmpty() const;

      void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);

      void display()const;
      //constructor/destructor

      CC();

      CC(const char* cc_name, unsigned long long cc_no, short cvv, short expMon=12, short expYear=26);

      ~CC(); //deconstructor





   };

}
#endif // !SENECA_CC_H_


