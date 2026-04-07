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
                                       Functions check if  integer entered if it is valid integer, no letters,spaces, and if the integer is less than the avabaile menu numbers and more than 0
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
#include <sstream>
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   //Nikola
   int Utils::getInt() {
      int value{};
      bool done = false;
      while (!done) {
         // Read the input
         string line;
         getline(cin, line);

         //1. Empty input
         if (line.empty()){
           // cout << ""; // change this back
            continue;
         }

         // 2.  Try  to parse int to see if it is valiate integer input
         std::stringstream ss(line);
         ss >> value;

         if (ss.fail()) {
            cout << "Invalid Integer: ";
            continue;
         }

         //3. Check for trailing characters
         char leftover{};
         if (ss >>leftover) {
            cout << "Only an integer please! ";
            continue;
         }

         // here, passed valid integer

         done = true;
      }
      //returns the valid integer
      return value;
   }

   //Nikola

   int Utils::getInt(int min, int max) {
      int value{};
      bool done = false;

      while (!done) {
          value = getInt(); // get the integer 
          // checks if int is between 0 and max number of menu numbers 
          // if more than max or less than 0 it fails
          if (value < min || value > max) {
            
            cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
          } else {
            done = true;
          }
      }
      return value;
   }

   char* Utils::makeBillFileName(char *filename, size_t billNo) const
   {
      char billFileName[21] = "bill_";
      size_t temp = billNo;
      int cnt = 5;
      int length;
      // Calculate the number of digits
      do
      {
         cnt++;
         temp /= 10;
      } while (temp > 0);
      length = cnt;
      // Convert each digit to character from the end
      while (billNo > 0)
      {
         billFileName[--cnt] = (billNo % 10) + '0';
         billNo /= 10;
      }
      // Handle the case when billNo is 0
      if (billFileName[cnt - 1] == '\0')
      {
         billFileName[--cnt] = '0';
      }
      // Attach .txt to the end of the file name
      for (int i = 0; ".txt"[i]; i++)
      {
         billFileName[length++] = ".txt"[i];
      }
      billFileName[length] = '\0';
      strcpy(filename, billFileName);
      return filename;
   }
}