#include <iostream>

using namespace std;

// Link: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html

int main()
{
    // Pointers
    int *ptr;
    int a = 5;
    ptr = &a;
    cout<<ptr<<&a<<*ptr<<a<<endl;

    *ptr = 7; // updates the value at the memory address where pointer is already pointing
    cout<<*ptr<<a<<endl;

    int b = 10;

    ptr = &b; // change the address where the pointer points to
    cout << ptr<< *ptr<<endl;

    // Uninitialized pointer
    int * ptr2;
    *ptr2 = 10;
    cout<< ptr2<< *ptr2<<endl;

}