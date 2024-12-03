#include "MyVector.h"

template <class T>
inline MyVector<T>::MyVector()
{
    size = 0;
    arr = nullptr;
}

template <class T>
MyVector<T>::MyVector(int n)
{
    size = n;
    arr = new T[n];
}

template <class T>
MyVector<T>::MyVector(T *a, int n)
{
    size = n;
    arr = a;
}

template <class T>
MyVector<T>::MyVector(const MyVector &v)
{
    size = v.getSize();
    arr = new T[size];

    for (int i = 0; i < size; ++i)
        arr[i] = v[i];
}

template <class T>
MyVector<T>::~MyVector()
{
    size = 0;
    delete[] arr;
    arr = nullptr;
}

template <class T>
int MyVector<T>::getSize()
{
    return size;
}

template <class T>
T MyVector<T>::getItem(int index)
{
    if (0 <= index && index < size)
        return arr[i];
    throw invalid_argument("Invalid index");
}
