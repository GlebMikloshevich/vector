//
// Created by gleb on 24.10.2020.
//
#include <iostream>
#include "Vector.h"

template <class Type>
Vector<Type>::Vector(int startCapacity) {
    if (startCapacity <= 0){
        capacity = DEFAULT_CAPACITY;
    } else {
        capacity = startCapacity;
    }
    ptr = new Type[capacity];
    size = 0;
}

template <class Type>
Vector<Type>::Vector(const Vector<Type>& arr) {
    ptr = new Type [arr.capacity];
    size = arr.size;
    capacity = arr.capacity;
    for (int i=0; i<size; i++)
        ptr[i] = arr.ptr[i];
}

template <class Type>
Vector<Type>::~Vector() {
    delete[] ptr;
}

template  <class Type>
Vector<Type>& Vector<Type>::operator =(const Vector<Type> &arr) {
    if (this==&arr)
        return *this;
    if (capacity != arr.capacity) {
        delete[] ptr;
        ptr = new Type[arr.capacity];
        capacity = arr.capacity;
    }
    size = arr.size;
    for (int i=0; i<size; i++)
        ptr[i] = arr.ptr[i];
    return *this;
}

template  <class Type>
Type& Vector<Type>::operator [](int index) {

        if (size == capacity)
            increaseCapacity(size+1);
        if (index == size){
            size++ ; //дублирует insert
    }
    if (index < 0 || index > size)
        //throw std::out_of_range("out of bound exception");
        throw ArrayException();
    else
        return ptr[index];
}

template <class Type>
void Vector<Type>::insert(Type elem, int index) {
    if (index < 0 || index > size)
        throw ArrayException();

    if (size == capacity)
        increaseCapacity(size+1); //увеличить capacity
        for(int i=size -1; i >= index; i--)
            ptr[i+1] = ptr[i];
        size++ ;
        ptr[index] = elem;
}

template<class Type>
void Vector<Type>::insert(Type elem) {
    insert(elem, size);
}

template  <class Type>
void Vector<Type>::remove(int index) {
    if (index < 0 || index >= size)
        throw ArrayException();
    for (int i=index; i < size-1; i++)
        ptr[i] = ptr[i +1];
    ptr[size-1]=Type();
    size-- ;
}

template  <class Type>
int Vector<Type>::getSize() const {
    return size;
}

template  <class Type>
std::ostream& operator <<(std::ostream& out, const Vector<Type>& arr) {
    out << '[';
    for (int i = 0; i < arr.getSize(); i++)
        if (arr.getSize() - 1 != i)
            out << arr.ptr[i] << ' ';
        else
            out << arr.ptr[i];
    out<<']';

    return out;
}

//private
template  <typename Type>
void Vector<Type>::increaseCapacity(int newCapacity) {
    capacity = newCapacity < capacity*2 ? capacity*2 : newCapacity;
    Type* newPtr = new Type[capacity];
    for (int i=0; i<size; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}




