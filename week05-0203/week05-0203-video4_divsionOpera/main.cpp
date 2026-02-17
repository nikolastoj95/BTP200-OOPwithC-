#include <iostream>
#include <cstring>
using namespace std;

#define CAP 32

class Ints {
    int elements[CAP]; // to point dynamic array
    int size;
    public:
    Ints(){
        size =0;
    }
    Ints (int p_size, const int* p_elements) {
        if (p_size > 0 && p_elements !=nullptr) {
            size = p_size<=CAP?p_size:CAP;
            for (int i= 0; i< size;i++){
                elements[i] = p_elements[i];
            }
        } else {
            size =0;
        }
    }
    void display(const char* msg){
        if (size >0) {
            cout << msg <<": ";
            for (int i =0; i<size; i++){
                cout << elements[i] << (i==size-1?'.':',');
            }
        } else {
            cout << "No data ";
        }
        cout << endl;
    }
};

int main (void) {
    const int size = 7;
    int cents[size] = {1234,632, 711, 422, 999,810,1111};
    Ints cnts(size,  cents);
    cnts.display("Cents");

    return 0;
}