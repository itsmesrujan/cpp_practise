// explicit constructor - it avoids implicit call to the constructor.
// Use of explicit keyword
#include<iostream>

class Base{
    int b_var;
public:
    Base(){ std::cout<<"Normal constructor"<<std::endl;  }
    explicit Base(int x):b_var(x){   std::cout<<"Param constructor"<<std::endl;  }
    void print(){
        std::cout<<"Base class member:: b_var:"<<b_var<<std::endl;
    }
};

void fun(Base b){
    b.print();
}

int main(){
    Base b1(10);
    Base b2 = 20;   // Implicit conversion
    
    fun(b1);
    fun(30);        // Implicit conversion
    return 0;
}
