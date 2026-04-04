/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad 
// Added two Functions int getInt() and int getInt(min,max) -  Author: Nikola Stojanovic, StNo: 027 369 149, Email: nstojanovic@myseneca.ca
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name                Date            Reason
// Nikola Stojanovic   03/20/2026      Added two functions in ms2, int getInt() and int getInt(min,max) for input integer  entry  for the menu choice selection
                                       
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
   class Utils {
   public:
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;

      // Nikola Stojanovic 027 369 149
      int getInt();
     // Nikola Stojanovic 027 369 149
      int getInt(int min, int max);
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
