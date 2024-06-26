// Difference between reference and pointer in C++
/* Memory Address - Same memory address for reference and different for pointer
 * Reassignment is not possible with reference as we have type bound for reference and we can't break that.
 * NULL value
 * Arithmetic operations - not provided for references
 * Indirection - In pointer we can have n no of indirections where as in reference you have only one indirection.
 */
#include<iostream>

int main()
{
    // Memory address
    int i  = 10;
    int &r = i;     // you can't assign a NULL value to a reference
    int *p = NULL;
    p = &i;

    std::cout<<&i<<'\t'<<&r<<'\t'<<&p<<std::endl;

    //Reassignment
    int var = 90;
    r = var;
    p = &var;
    std::cout<<std::endl<<i<<'\t'<<*p<<std::endl;

    // p++ is possible but r++ is not possible.
    // You can increment the address of reference if you want - (&r)++ is possible

    // Indirection
    int **ptr   = &p;
    int ***pptr = &ptr;

    std::cout<<"\np:"<<p<<"\nptr:"<<ptr<<"\npptr:"<<pptr<<std::endl;
    std::cout<<"\n*p:"<<*p<<"\n**ptr:"<<**ptr<<"\n***pptr:"<<***pptr<<std::endl;

    int &rr = r;
    int &rrr = rr;
    std::cout<<"\nrrr:"<<rrr<<"\nrr:"<<rr<<"\nr:"<<r<<"\ni:"<<i<<std::endl;

    return 0;
}
