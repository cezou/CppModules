#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) {
	
	if (n == 0)
		return;
	this->_size = n;
	this->_array = new T[n];
	if (!this->_array)
		throw std::bad_alloc();
	for (unsigned int i = 0; i < n; ++i) {
		this->_array[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0) {
	if (!other._size)
		return;
	this->_size = other.size();
	this->_array = new T[this->_size];
	if (!this->_array)
		throw std::bad_alloc();
	for (unsigned int i = 0; i < this->_size; ++i) {
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	if (this->_array) {
		delete[] this->_array;
		this->_array = NULL;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	if (this->_array)
		delete[] this->_array;
	this->_array = NULL;
	this->_size = other.size();
	if (this->_size == 0) 
		return *this;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; ++i) {
		this->_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
/**
 *  @brief Overloaded subscript operator to access elements in the array.
 *  @param index The index of the element to access.
 *  @return A reference to the element at the specified index.
 */
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw IndexOutOfBoundsException(index, this->_size);
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	std::cout << "Array::operator[] const called " << index << std::endl;
	if (index >= this->_size)
		throw IndexOutOfBoundsException(index, this->_size);
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

template <typename T>
Array<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(unsigned int index, unsigned int size) {
	std::ostringstream oss;
	oss << RED "Error: Index " BOLD << index << R RED" is out of bounds for Array of size " BOLD << size << R;
	_message = oss.str(); // Store the formatted message
}

// what() implementation
template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
	return _message.c_str(); // Return the stored message
}

