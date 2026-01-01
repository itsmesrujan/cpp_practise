/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// C++ 11 features

#include <iostream>

class B{
    int x, y;
public:
    B(int a, int b):x(a),y(b){}
    void print(){
        std::cout<<x<<'\t'<<y<<std::endl;
    }
};

// Implicitly initialize objects to return
B f(int w, int o){
    return {w, o};
}

// Implicitly initialize function parameter
void fun(B obj){
    obj.print();
}

class A{
    int arr[3];
public:
    // Uniform initialization
    A(int x, int y, int z):arr{x,y,z}{}

    void print(){
        int arrsz = sizeof(arr)/sizeof(arr[0]);
        for(int i=0; i<arrsz; ++i){
            std::cout<<arr[i]<<'\t';
        }
        std::cout<<std::endl;
    }
};

int main(void)
{
    std::cout<<"Hello World"<<std::endl;

    // Uniform initialization
    int *ptr = new int[10]{1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<10; ++i){
        std::cout<<*(ptr+i)<<"\t";
    }
    std::cout<<std::endl;

    A obj(90,80,70);
    obj.print();

    B bObj = f(35, 77);     // Implicitly initialize objects to return
    bObj.print();

    fun({87, 65});          // Implicitly initialize function parameter

    return 0;
}
