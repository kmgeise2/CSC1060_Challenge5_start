#pragma once
#include <iostream>

using namespace std;

template <class T>
class DynamicArray
{
public:
	//constructors
	DynamicArray();
	DynamicArray(int ms);

	//destructor
	//~DynamicArray();

	//functions
	// Uncomment functions as you code them
	
	//int length();
	//T get(int index);
	void print();
	void push(T element);
	T pop();
	//void insertAt(T element, int index);
	//T remove(int index);

	//overload operators
	T operator [](int i);

private:
	T* arr;
	int maxsize;
	int size;

	void resize();
};
template<class T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
template<class T>
inline void DynamicArray<T>::push(T element)
{
	if (size == maxsize) resize();
	arr[size++] = element;
}

template<class T>
inline T DynamicArray<T>::pop() throw (length_error)
{
	if (size > 0) return arr[--size];
	else throw length_error("Can't pop from an empty list.");
}

template<class T>
DynamicArray<T>::DynamicArray() 
{
	maxsize = 5;
	size = 0;
	arr = new T[maxsize];
}
template<class T>
DynamicArray<T>::DynamicArray(int ms)
{
	if (ms > 0)maxsize = ms;
	size = 0;
	arr = new T[maxsize];
}

template<class T>
inline T DynamicArray<T>::operator [](int i) 
{
	return arr[i];
}
template<class T>
inline void DynamicArray<T>::resize() 
{
	// Double the size of an array
	// by creating a temporary array
	maxsize *= 2;
	T* temp = new T[maxsize];
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}