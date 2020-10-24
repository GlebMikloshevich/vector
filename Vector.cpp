//
// Created by gleb on 24.10.2020.
//
#include <iostream>
#include "Vector.h"

Vector::Vector(int startCapacity) {
    if (startCapacity <= 0){
        capacity = DEFAULT_CAPACITY;
    } else {
        capacity = startCapacity;
    }
    ptr = new int[capacity];
    size = 0;
}

Vector::Vector(const Vector& arr) {
    ptr = new int [arr.capacity];
    size = arr.size;
    capacity = arr.capacity;
    for (int i=0; i<size; i++)
        ptr[i] = arr.ptr[i];
}

Vector::~Vector() {
    delete[] ptr;
}

Vector& Vector::operator =(const Vector &arr) {
    if (this==&arr)
        return *this;
    if (capacity != arr.capacity) {
        delete[] ptr;
        ptr = new int[arr.capacity];
        capacity = arr.capacity;
    }
    size = arr.size;
    for (int i=0; i<size; i++)
        ptr[i] = arr.ptr[i];
    return *this;
}

int& Vector::operator [](int index) {
    if (index == size){
        size++ ; //дублирует insert
        if (size == capacity)
            increaseCapacity(size+1);
    }
    if (index < 0 || index > size)
        //throw std::out_of_range("out of bound exception");
        throw ArrayException();
    else
        return ptr[index];
}

void Vector::insert(int elem, int index) {
    if (index < 0 || index > size)
        throw ArrayException();

    if (size == capacity)
        increaseCapacity(size+1); //увеличить capacity
        for(int i=size -1; i >= index; i--)
            ptr[i+1] = ptr[i];
        size++ ;
        ptr[index] = elem;
}

void Vector::insert(int elem) {
    insert(elem, size);
}

void Vector::remove(int index) {
    if (index < 0 || index >= size)
        throw ArrayException();
    for (int i=index; i < size-1; i++)
        ptr[i] = ptr[i +1];
    ptr[size-1]=0;
    size-- ;
}

int Vector::getSize() const {
    return size;
}

std::ostream& operator <<(std::ostream& out, const Vector& arr) {
    for (int i =0; i < arr.getSize(); i++)
        if (arr.getSize()-1 != i)
            out<<arr.ptr[i]<<' ';
        else
            out<<arr.ptr[i];
    return out;
}
//private
void Vector::increaseCapacity(int newCapacity) {
    capacity = newCapacity < capacity*2 ? capacity*2 : newCapacity;
    int* newPtr = new int[capacity];
    for (int i=0; i<size; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}




