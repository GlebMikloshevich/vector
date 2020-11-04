#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
int main() {
    setlocale(LC_ALL, "Russian");

    std::cout<<"Vector <Vector<int> >"<<std::endl;
    Vector< Vector<int> > arr(4);
    Vector<Vector<int> > brr(4);

    for(int i=0; i<4; i++){
        arr.insert(Vector<int>());
        for (int j = 0; j <= i; j++)
            arr[i].insert(j);
    }

    for(int i=0; i<5; i++){
        brr.insert(Vector<int>());
        for (int j = 0; j <= i; j++)
            brr[i].insert(j);
    }
    std::cout<<arr<<std::endl;
    std::cout<<brr<<std::endl;
    arr.insert(0, brr);
    std::cout<<arr<<std::endl;
    /*
    std::cout<<arr[3]<<std::endl;
    std::cout<<arr<<std::endl;
    arr[4] =  Vector<int>();
    arr[4].insert(10);
    std::cout<<arr<<std::endl;
    for (int i = 0; i< 7; i++)
        arr.insert(Vector<int>());
    std::cout<<arr<<std::endl;
    for (int i = 0; i<3; i++)
        arr.remove(0);
    std::cout<<arr<<std::endl;
    */
    /*
    std::cout<<"Vector <int>"<<std::endl;
    Vector<int> arr1(4);
    for (int i = 0; i <4; i++)
        arr1.insert(i+1);
    std::cout<<arr1<<std::endl;
    for(int i=0; i<8; i+=2)
        arr1.insert(10+i,i);
    std::cout<<arr1<<std::endl;
    for(int i=1; i<8; i+=2)
        arr1[i]=20+i;
    std::cout<<arr1<<std::endl;
    for(int i=6; i>=0; i-=3)
        arr1.remove(i);
    std::cout<<arr1<<std::endl;
    */
}
