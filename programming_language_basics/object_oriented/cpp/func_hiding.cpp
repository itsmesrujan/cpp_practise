// Function hiding

#include <iostream>

class Base{
public:
    void func() {   std::cout<<"Void"<<std::endl;   }
    int func(int i, int j){
        std::cout<<"Base int: "<<i<<j<<std::endl;
        return 0;
    }
};

class Derived: public Base
{
public:
    using Base::func;       // Use this line to fix function hiding
                            // or we can use base class with scope resolution operator.
    void func(char a)
    {
        std::cout<<"Derived char: "<<a<<std::endl;
    }
};

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro"<<std::endl;
    Derived D;
    D.func(110,0);
    return 0;
}
