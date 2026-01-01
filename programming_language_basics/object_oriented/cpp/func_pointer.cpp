// Function pointer
/* 1. What is function pointer and how to create them?
 * Ans: Normal pointer stores the address of another variables, function pointer stores address of another function.
 *
 * 2. Calling a function using a function pointer
 *
 * 3. How to pass a function pointer as an argument?
 * 
 * 4. How to return a function pointer?
 * 
 * 5. How to use arrays of function pointer?
 * 
 * 6. Where to use function pointers?
 *
 */

#include <iostream>

int mul(int a, int b)
{
    return (a*b);
}

int main()
{
    int i = 10;
    int *ptr = &i;

    std::cout<<"i: "<<i<<"\t&i:"<<&i<<"\t*ptr"<<*ptr<<"\tptr"<<ptr<<std::endl;

    int (*mulPtr)(int,int) = &mul;
    //or
    //int (*mulPtr)(int,int) = mul;

    int c = (*mulPtr)(10, 100);
    //or
    //int c = mulPtr(10, 100);

    std::cout<<"10 X 100 = "<<c<<std::endl;

    return 0;
}
