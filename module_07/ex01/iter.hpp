#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, size_t length, void (*func)(T &)) {
  for (size_t i = 0; i < length; i++)
    func(array[i]);
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
  for (size_t i = 0; i < length; i++)
    func(array[i]);
}

template <typename T> size_t typeLenght(T &t) {
  size_t arrayLenght = sizeof(t) / sizeof(t[0]);
  return arrayLenght;
}

template <typename T> void print(T &t) { std::cout << t << " " << std::endl; }

#endif