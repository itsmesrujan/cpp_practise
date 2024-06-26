// Function chaining in C++
// It gives good code analysis power

#include <iostream>

class Base{
    int _a,_b;
public:
    Base& seta(int a){  _a=a; return *this; }   // you should always return reference otherwise we may face undefined behavior
    Base& setb(int b){  _b=b;  return *this;   }    // you should always return reference.
    void print(){   std::cout<<"a="<<_a<<" b="<<_b<<std::endl; }
};

int main()
{
    Base b;
    b.seta(10).setb(20).print();
    // b.print();
    return 0;
}
