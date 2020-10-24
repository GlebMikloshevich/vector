//
// Created by gleb on 24.10.2020.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
class ArrayException {};
class Vector {


    // Хранилище элементов
    private:
        int* ptr;
        // Количество элемнетов в векторе (сейчас)
        int size;
        // Максимальный размер на данный момент
        int capacity;
        // стандартное значение capacity для конструктора
        static const int DEFAULT_CAPACITY = 10;
        // функция увеличения capacity при достижении конца вектора
        void increaseCapacity(int newCapacity);
    public:

        //Констркутор с указанием размера
        explicit Vector(int startCapacity=DEFAULT_CAPACITY);
        //Консруктор копирования
        Vector(const Vector& arr);
        //Деструктор
        ~Vector();

        //оператор присваивания =
        Vector& operator =(const Vector& arr);
        //оператор индексации []
        int& operator [](int index);
        // Вставка элемента
        void insert(int elem, int index);
        void insert(int elem);
        // Удаление элемента
        void remove(int index);
        // Получение количества элементов (длины вектора)
        int getSize() const;
        // Вывод
        friend std::ostream& operator <<(std::ostream& out, const Vector& arr);



};


#endif //VECTOR_VECTOR_H
