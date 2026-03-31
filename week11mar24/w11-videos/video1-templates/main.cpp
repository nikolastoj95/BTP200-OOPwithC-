#include <iostream>

//adding two varables

// int sum (int a, int b) {
//     int c ;
//     c = a+b;
//     return c;
// }

// double sum (double a, double b) {
//     double c = a +b;
//     return c;
// }

// std::string sum (std::string a, std::string b) {
//     std::string c = a + b;
//     return c;
// }

// want to reduce amount of code (from above just type is different)

template <typename T> //or <typename T> // or <class T> // T - type parameter
T sum (T a, T b) { // generic version of the three sum functions
    T c ;
    c = a+b;
    return c;
}

// Template - way to generate gernic function




int main() {
    int x = 5, y = 6 , z; // z is anwser

    z = sum (x,y);

    std::cout << "sum " << z << std::endl;

    double  m = 5.5, n = 6.6, o;
    o = sum(m,n); //12.1 // getting 11
    std::cout << "sum: " << o <<std::endl;

    std::string s1 = "Hello", s2 = " World", s3;

    s3 = sum (s1,s2);
     std::cout << "sum: " << s3 <<std::endl;




    return 0;
}