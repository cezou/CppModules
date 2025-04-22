#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>
# include <cstdlib> // For rand(), srand(), NULL
# include <ctime>   // For time()
# include <string>  // Added for std::string
# include <sstream> // Added for std::ostringstream
# include "../utils.hpp"

template <typename T>
class Array {
private:
	T*           _array;
	unsigned int _size;

public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array& other);
	~Array();
	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;

	class IndexOutOfBoundsException : public std::exception {
	private:
		std::string _message; // Member to store the formatted message
	public:
		IndexOutOfBoundsException(unsigned int index, unsigned int size); // Constructor to create the message
		virtual ~IndexOutOfBoundsException() throw() {} // Destructor
		virtual const char* what() const throw();
	};
};

# include "Array.tpp" // Include only once

#endif // ARRAY_HPP