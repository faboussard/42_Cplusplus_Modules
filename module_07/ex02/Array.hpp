#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

#define MAX_VALUE 1000

template <typename T> class Array {
private:
  T *_array;
  unsigned int _arraySize;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  ~Array();
  Array &operator=(const Array &other);

  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;

  unsigned int size() const;
};

#include "Array.tpp"

#endif