#include <iostream>
// #include <template.h>

template <typename T>
T myMax(T a, T b){
    return (a>b ? a : b);
}

template <typename T>
class Array{
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T>Array<T>::Array(T arr[], int z){
    if (!ptr){
        ptr = new T[z];
    }
    size = z;
}

template <typename T>void Array<T>::print(){
    std::cout<< size<<std::endl;
}

int main()
{
    int maxNum = myMax<int>(10,15);
    char c = myMax<char>('a', 'z');
    int arr[5]={1,2,3,4,5};
    Array<int> a(arr, 5);
    a.print();

    std::cout<<"int max num:"<<maxNum<<std::endl;
    std::cout<<"char  max num:"<<c<<std::endl;
    
    return 0;
}
