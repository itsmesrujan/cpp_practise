#include <iostream>

class A {
    int a;
    int b;
public:
    A():a{20}, b{10} 
    {
        std::cout<<"A Constructor"<<std::endl;
    }
    ~A()
    {
        std::cout<<"A Destructor"<<std::endl;
    }

    int add() {    return (a+b);   }
    friend int accessA(A &obj);
    friend class B;
};

class B
{
public:
    B()
    {
        std::cout<<"B constructor"<<std::endl;
    }
    ~B()
    {
        std::cout<<"B Destructor"<<std::endl;
    }
    void accessOtherClass(A &obj)
    {
        std::cout<<"class A object values in class B:"
                 <<obj.a
                 <<" "
                 <<obj.b
                 <<std::endl;
    }
};

int accessA(A &obj)
{
    return (obj.a*obj.b);
}

int main()
{
    std::cout<<"Main function start"<<std::endl;

    A obj;
    std::cout<<accessA(obj)<<std::endl;

    B obj1;
    obj1.accessOtherClass(obj);
    std::cout<<"Main function end"<<std::endl;
    return 0;
}
