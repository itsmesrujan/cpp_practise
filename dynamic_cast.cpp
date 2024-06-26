// dynamic_cast
/* 1. Work only on polymorphic base class (atleast one virtual function in base class) because it uses this information to decide about wrong down-cast.
 * 2. It is used for up-cast (D->B) and down-cast (B->D), but it is mainly used for down-cast.
 * 3. Using this cast has runtime overhead, because it checks object types at run time using RTTI (Run Time Type Information).
 * 4. If we are sure that we will never cast to wrong object then we should always avoid this cast and use static_cast.
 */

#include<iostream>
#include<exception>

class Base {
public:
    Base() {    std::cout<<"Base Constructor"<<std::endl;   }
    ~Base() {   std::cout<<"Base Destructor"<<std::endl;    }
    virtual void func();
};

void Base::func() {
    std::cout<<"Base class function"<<std::endl;
}

class Derived1:public Base{
public:
    Derived1() {    std::cout<<"Derived1 Constructor"<<std::endl;   }
    ~Derived1() {    std::cout<<"Derived1 Destructor"<<std::endl;   }
    void func() {   std::cout<<"Derived1 custom function"<<std::endl;    }
};

class Derived2:public Base {
public:
    Derived2() {    std::cout<<"Derived2 Constructor"<<std::endl;   }
    ~Derived2() {    std::cout<<"Derived2 Destructor"<<std::endl;   }
    void func() {   std::cout<<"Derived2 custom function"<<std::endl;    }
};

int main()
{
    Base *b1 = new Derived1;
    std::cout<<std::endl;
    Derived1 d1;
    // Derived2 d2;

    Base *b2 = dynamic_cast<Base *>(&d1);
    Derived1 *d3 = dynamic_cast<Derived1 *>(b2);
    if (NULL == d3){
        std::cout<<"dynamic cast threw NULL"<<std::endl;
    }else{
        std::cout<<"dynamic cast didn't throw NULL"<<std::endl;
    }

    std::cout<<std::endl;

    Derived2 d2;

    try{
        Derived1 &d4 = dynamic_cast<Derived1 &>(d1);
        std::cout<<std::endl<<"d4 cast success"<<std::endl<<std::endl;
    }catch(std::exception& e){
        std::cout<<std::endl<<e.what()<<std::endl<<std::endl;
    }

    return 0;
}
