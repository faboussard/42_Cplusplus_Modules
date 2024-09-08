#pragma once

template <typename T>
class Array
{
private:
	T *_arrayPointer;
	unsigned int _arraySize;

public:
	Array();
	~Array();
	Array(unsigned int n);
	Array &operator=(const Array &other);
	Array(const Array &other);

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index)	const;

	unsigned int size() const;

	static void print_template(T value);

};