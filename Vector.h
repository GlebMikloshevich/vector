//
// Created by gleb on 24.10.2020.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
class ArrayException {};
template <class Type>
class Vector{

    private:
        // Количество элемнетов в векторе (сейчас)
        int size;
        // Максимальный размер на данный момент
        int capacity;
        // стандартное значение capacity для конструктора
        static const int DEFAULT_CAPACITY = 10;
        // функция увеличения capacity при достижении конца вектора
        void increaseCapacity(int newCapacity);

    public:
        //Указатель на элементы вектора
        Type* ptr;
        //Констркутор с указанием размера
        explicit Vector(int startCapacity=DEFAULT_CAPACITY);
        //Консруктор копирования
        Vector(const Vector<Type>& arr);
        //Деструктор
        ~Vector();

        //оператор присваивания =
        Vector<Type>& operator =(const Vector<Type>& arr);
        //оператор индексации []
        Type& operator [](int index);
        // Вставка элемента
        void insert(Type elem, int index);
        void insert(Type elem);
        // Удаление элемента
        void remove(int index);
        // Получение количества элементов (длины вектора)
        int getSize() const;
        // Вывод
        //friend std::ostream& operator <<(std::ostream& out, const Vector<Type>& arr);



};


#endif //VECTOR_VECTOR_H
