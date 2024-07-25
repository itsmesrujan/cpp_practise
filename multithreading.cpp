
#include <iostream>
#include <thread>

//multi-threading

//Using function pointer
void print(int a){
    for (int i=0; i<a;++i){
        std::cout<<"function pointer is printing:"<<a<<std::endl;
    }
}

class A{
public:
    void operator()(int x){
        std::cout<<"function object:"<< x <<std::endl;
    }
    void print(std::string str){
        std::cout<<"A class print:"<<str<<std::endl;
    }
    static void printStatic(std::string str, float fl){
        std::cout<<"printStatic::fl"<<str<<"\t"<<fl<<std::endl;
    }
};

int main(void)
{
    // std::cout<<"Hello World";
    std::thread thrdObj(print, 10);

    auto x = [](int j){
        std::cout<<"Print :"<<j<<std::endl;
    };
    std::thread lambThrd(x, 100);
    std::thread funObj(A(), 50);

    A objA;

    std::thread nonStatObj(&A::print, &objA, "Hello Srujan");

    std::thread statObj(&A::printStatic, "STATIC HELLO", 100);

    thrdObj.join();
    lambThrd.join();
    funObj.join();
    nonStatObj.join();
    statObj.join();
    return 0;
}
