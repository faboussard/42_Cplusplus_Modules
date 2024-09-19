#include <iostream>
#include <string>

template <typename T> Array<T>::Array() : _array(NULL), _arraySize(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _arraySize(n) {
  _array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _arraySize(0) {
  *this = other;
}

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    delete[] _array;

    _arraySize = other._arraySize;
    _array = new T[_arraySize];

    for (unsigned int i = 0; i < _arraySize; ++i) {
      _array[i] = other._array[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _arraySize) {
    throw std::out_of_range("Index out of range");
  }
  return _array[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _arraySize) {
    throw std::out_of_range("Index out of range");
  }
  return _array[index];
}

template <typename T> void printArray(const Array<T> &array) {
  std::cout << "[";
  for (unsigned int i = 0; i < array.size(); ++i) {
    if (i != 0)
      std::cout << ", ";
    std::cout << array[i];
  }
  std::cout << "]" << std::endl;
}

template <typename T> unsigned int Array<T>::size() const { return _arraySize; }
