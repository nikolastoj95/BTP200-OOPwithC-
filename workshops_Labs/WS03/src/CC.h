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


