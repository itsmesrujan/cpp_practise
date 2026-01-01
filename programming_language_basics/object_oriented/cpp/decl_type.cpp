// decltype in C++
// We use decltype to check the type of an expression
#include <iostream>

// Before using decltype
template<typename T1, typename T2>
T2 add(T1 a, T2 b)
{
    return a+b;
}

// After using decltype
template<typename T1, typename T2>
auto declAdd(T1 a, T2 b) -> decltype(a+b)
{
    return a+b;
}

int main()
{
    std::cout<<add(1, 1.8)<<std::endl<<add(1.8, 1)<<std::endl<<std::endl;
    std::cout<<declAdd(1, 1.8)<<std::endl<<declAdd(1.8, 1)<<std::endl;

    return 0;
}
