//Difference between range based for loop and for_each in C++

#include <iostream>
#include <vector>
#include <algorithm>

void print(int i) {  std::cout<<i<<"\t";    }

int main() {
    std::vector <int> iVec;
    int arr[10];
    // Legacy for loop
    for (int i=0; i<10; ++i) {
        iVec.push_back(i);
        arr[i] = i;
    }

    // Range based for loop
    for(int i:iVec) {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl<<"Print array through range based for loop"<<std::endl;

    // Range based for loop
    for(int i:arr) {
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;

    // for_each loop::lambda expression
    for_each(iVec.begin(), iVec.end(), [](int i){std::cout<<i<<"\t";});
    std::cout<<std::endl;
    
    // for_each::lambda alternative through a function
    for_each(iVec.begin()+2, iVec.end(), print);
    std::cout<<std::endl;

    // Range based for loop doesn't allow a particular range, we will have iterate all the elements in an array or vector.
    
    // In for_each loop, we can't consider array however it will allow a particular range.

    return 0;
}
