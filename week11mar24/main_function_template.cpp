#include <iostream>
using namespace std;
// Agenda - March25 week 11
// - function template 
// - class template
// - constrained cast: static_cast, reinterpret_cast, const_cast, dynamic_cast



// Review topics
// - early binding and late binding (dynamic dispatch)
// - Interface and abstract class
// - Array of pointers 
// - Unit test on interface
// - copy operations - code localization (private member function and direct call)
// - assigning temporaty objects: *this = ClassName(...)
// - prohibiting copies (construction and assignment)

//overriding - 
//shawdowing - dervied class preventing access to base class function 

// Function Template

//std::string; // btd 305

struct MyType {
    int height;
    double income;
    MyType operator+ (const MyType mt) {
        MyType temp = *this;
        temp.height += mt.height;
        temp.income += mt.income;

        return temp; // return by value
        
    }
    MyType (int h, double i) {
    }
    MyType(){};
    MyType (int x) {
        MyType temp = *this;
        temp.height +=x;
    }
};



// int sum (int a, int b) {
//     int c = a+b;
//     return c;
// }
// //use overloading

// double sum (double a, double b) {
//     double c = a+b;
//     return c;
// }
// std::string sum (std::string a, std::string b) {
//     std::string c = a+b;
//     return c;
// }

// MyType sum (MyType a, MyType b) {
//     MyType c = a+b;
//     return c;
// }

//template function  (- familt of functions)

template <typename T, typename U> // T - generic type (type parameter) // 
 // first line // if all functions are same logic -> but diff logic will not work 
T sum (T a, U b) {
    Tc;
    c = a+b;
    return c;
}

/* Advantages:
   * - reuseability (versatility)
   * - efficient code
   * - 
*/
/* Disadvantage:
    * - logic has to be same
    * - the type used must support operations invloved in the function logic 
*/


// using MyType watch for +, <<


//template instantiation - process followed by compiler for creating version of
    // a template function for a specfic type



int main() {

    int x = 5, y = 10 , z;
    double  xd = 5.5, yd = 10.6, zd ;
    
    std::string xs ="Hello", ys = "World", zs;

    MyType xmt = {81,22.2}, ymt = {91,33.3},zmt;




    z = sum <int>(x,y);
    zd = sum <double>(xd, yd); // it truncates it so still 15 
    zs = sum<string>(xs,ys);

    zmt = sum<MyType>(xmt, ymt);

    cout << "sum (int) : " << z << endl;
    cout << "sum (double) : " << zd << endl;
    cout << "sum (string) : " << zs << endl;

    cout << "sum (MyType) : " << zmt << endl;

    

    return 0;
}