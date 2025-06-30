#pragma once

#include <cstddef>
#include "../../utils.hpp"


class Jacobsthal {
private:
    size_t _previous;
    size_t _value;

	Jacobsthal& operator=(const Jacobsthal& other){
		if (this != &other) {
			_previous = other._previous;
			_value = other._value;
		}
		return *this;
	}
	Jacobsthal(const Jacobsthal& other) {
		*this = other;
	}

public:
    Jacobsthal() : _previous(1), _value(3) {}
	
    size_t getValue() const { return _value; }
    size_t getPrevious() const { return _previous; }

    Jacobsthal& operator++() {
        size_t temp = _value + 2 * _previous;
        _previous = _value;
        _value = temp;
        return *this;
    }

    Jacobsthal operator++(int) {
        Jacobsthal temp = *this;
        ++(*this);
        return temp;
    }

	operator int() const {
        return _value;
    }
	// operator << without friend
};

inline std::ostream& operator<<(std::ostream& os, const Jacobsthal& j) {
	os << "Jacobsthal(" << j.getPrevious() << ", " << j.getValue() << ")";
	return os;
}
