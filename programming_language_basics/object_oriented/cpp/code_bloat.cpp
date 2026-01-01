// Code bloat is the production of code that is perceived unnecessarily long, slow, or otherwise wasteful of resources
#include <iostream>

class A
{
    int _x;
public:
    inline void print(){std::cout<<"Line 1"<<std::endl; std::cout<<"Line 2"<<std::endl;}
};

int main()
{
    // Example-1
    // std::string str("This is a sample test");
    // std::cout<< str <<std::endl;
    std::cout<<"This is a sample test"<<std::endl;

    // Example-2
    A obj;
    obj.print();

    return 0;
}
