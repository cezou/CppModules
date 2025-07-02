#pragma once

#include <iostream>
#include "../../utils.hpp"

extern size_t g_comparison_count;

class IntC 
{
private:
    int _value;

public:
    IntC(int value = 0) : _value(value) {}
	IntC(const IntC& other) : _value(other._value) {}
	IntC& operator=(const IntC& other) {
		if (this != &other) {
			_value = other._value;
		}
		return *this;
	}
    
    operator int() const {
        return _value;
    }
    
    bool operator<(const IntC& other) const {
        g_comparison_count++;
        return _value < other._value;
    }
	bool operator>(const IntC& other) const {
		g_comparison_count++;
		return _value > other._value;
	}
	bool operator<=(const IntC& other) const {
		g_comparison_count++;
		return _value <= other._value;
	}
	bool operator>=(const IntC& other) const {
		g_comparison_count++;
		return _value >= other._value;
	}
	bool operator==(const IntC& other) const {
		g_comparison_count++;
		return _value == other._value;
	}
	bool operator==(int value) const {
		g_comparison_count++;
		return _value == value;
	}
	bool operator!=(const IntC& other) const {
		g_comparison_count++;
		return _value != other._value;
	}
	
	int getValue() const {
		return _value;
	}
};

inline std::ostream& operator<<(std::ostream& os, const IntC& intc) {
	os << static_cast<int>(intc);
	return os;
}

// Opérateur externe pour int == IntC
inline bool operator==(int value, const IntC& intc) {
	extern size_t g_comparison_count;
	g_comparison_count++;
	return value == (int)intc;
}


