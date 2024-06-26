// const_cast in C++
// The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or references. Where T must be a pointer, reference, or pointer to member type.
#include <iostream>

//Use-case-1
// int main()
// {
//     // Example-1
//     const int a1=10;
//     const int *b1=&a1;
//     int *d1=const_cast<int *>(b1);
//     *d1 = 15;   //Invalid and Undefined behavior!
//     std::cout<<"a1: "<<a1<<std::endl;
//     std::cout<<"*d1: "<<*d1<<std::endl;

//     //Example-2
//     int a2 = 20;
//     const int *b2 = &a2;
//     int *c2=const_cast<int *>(b2);
//     std::cout<<"before assignment *c2: "<<*c2<<std::endl;
//     *c2 = 30;    //Valid
//     std::cout<<"after  assignment *c2: "<<*c2<<std::endl;

//     return 0;
// }

// Use-case-2
// When we need to call third-party library where it is taking variable object as non-const but not changing that
void thirdPartyLib(int *x)
{
    int k=10;
    std::cout<<k+(*x);
}

int main()
{
    const int x = 10;
    const int *pt = &x;
    thirdPartyLib(const_cast<int *>(pt));

    return 0;
}

//Summary:
//We shouldn't use this const_cast until it is actually required as per the requirement
/*1. Use only when you have to.
 *2. Use only when the actual refered object/variable is not const
 *3. Use only when we need to deal with third-party library and some API
 *   with non-const as an input (make sure API is not changing the variable
 *   value with in API)
 */
