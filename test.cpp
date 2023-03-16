#include <iostream>
using namespace std;

class A {
public:
    virtual void func() {
        cout << "a";
    }
};

class B: A{
public:

};