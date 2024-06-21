// What is the use of auto keyword in c++ 
// Ans: It is used for type deduction

#include <iostream>
#include <typeinfo>

class D{};

int main()
{
    auto a = 10;
    auto b = 15.71;
    auto c = D();
    auto e = new D();

    std::cout<<typeid(a).name()<<std::endl;
    std::cout<<typeid(b).name()<<std::endl;
    std::cout<<typeid(c).name()<<std::endl;
    std::cout<<typeid(e).name()<<std::endl;

    return 0;
}

