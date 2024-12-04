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
    for (int i = 0; i < size; ++i)
        arr[i] = 0;
}

template <class T>
MyVector<T>::MyVector(T *a, int n)
{
    size = n;
    arr = new T[n];
    for (int i = 0; i < n; ++i)
        arr[i] = a[i];
}

template <class T>
MyVector<T>::MyVector(const MyVector &v)
{
    size = v.getSize();
    arr = new T[size];

    for (int i = 0; i < size; ++i)
        arr[i] = v.arr[i];
}

template <class T>
MyVector<T>::~MyVector()
{
    size = 0;
    delete[] arr;
    arr = nullptr;
}

template <class T>
int MyVector<T>::getSize() const
{
    return size;
}

template <class T>
T MyVector<T>::getItem(int index)
{
    if (index < 0 || index >= size)
        throw invalid_argument("Error: Invalid index");
    return arr[index];
}

template <class T>
void MyVector<T>::setItem(T value, int index)
{
    if (index < 0 || index >= size)
        throw invalid_argument("Error: Invalid index");
    
    arr[index] = value;
}

template <class T>
void MyVector<T>::add(T value)
{
    T* newArr = new T[size + 1];
    for (int i = 0; i < size; ++i)
        newArr[i] = arr[i];
    newArr[size++] = value;

    delete[] arr;
    arr = newArr;
}

template <class T>
void MyVector<T>::addRange(T *a, int n)
{
    T* newArr = new T[size + n];

    for (int i = 0; i < size; ++i)
        newArr[i] = arr[i];

    for (int i = 0; i < n; ++i)
        newArr[i + size] = a[i];

    size += n;

    delete[] arr;
    arr = newArr;
}

template <class T>
void MyVector<T>::clear()
{
    size = 0;
    delete[] arr;
    arr = nullptr;
}

template <class T>
bool MyVector<T>::contains(T value)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return true;

    return false;
}

template <class T>
void MyVector<T>::toArray(T *arr, int &n)
{
    n = size;
    arr = new T[n];
    for (int i = 0; i < n; ++i)
        arr[i] = this->arr[i];
}

template <class T>
bool MyVector<T>::equals(const MyVector &v)
{
    if (size != v.getSize())
        return false;
    
    for (int i = 0; i < size; ++i)
        if (arr[i] != v.arr[i])
            return false;
    
    return true;
}

template <class T>
int MyVector<T>::indexOf(T value)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;
    return -1;
}

template <class T>
int MyVector<T>::lastIndexOf(T value)
{
    int index = -1;

    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            index = i;
    
    return index;
}

template <class T>
void MyVector<T>::insert(T value, int index)
{
    if (index < 0 || index > size)
        throw invalid_argument("Error: Invalid index");

    T* newArr = new T[size + 1];

    bool added = 0;
    for (int i = 0; i < size; ++i)
    {
        if (i == index)
        {
            newArr[i] = value;
            added = 1;
            newArr[i + 1] = arr[i];
        }
        else
            newArr[i + added] = arr[i];
    }

    ++size;
    delete[] arr;
    arr = newArr;
}

template <class T>
void MyVector<T>::remove(T value)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            ++count;
    
    if (count == 0)
        return;

    T* newArr = new T[size - count];
    count = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] != value)
            newArr[count++] = arr[i];
    
    size = count;
    delete[] arr;
    arr = newArr;
}

template <class T>
void MyVector<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw invalid_argument("Error: Invalid index");

    T* newArr = new T[--size];

    for (int i = 0; i < index; ++i)
        newArr[i] = arr[i];

    for (int i = index; i < size; ++i)
        newArr[i] = arr[i + 1];
    
    delete[] arr;
    arr = newArr;
}

template <class T>
void MyVector<T>::reverse()
{
    for (int i = 0; i < size / 2; ++i)
    {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

template <class T>
string MyVector<T>::toString()
{
    if (size == 0)
        return "Empty";

    string result = "[";
    for (int i = 0; i < size; ++i)
    {
        if constexpr (std::is_same<T, Fraction>::value)
            result += arr[i].toString();
        else
            result += std::to_string(arr[i]);

        if (i < size - 1)
            result += ", ";
    }
    result += "]";
    return result;
}

template <class T>
void MyVector<T>::sortAsc()
{
    for (int i = 1; i < size; ++i)
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <class T>
void MyVector<T>::sortDesc()
{
    for (int i = 1; i < size; ++i)
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
