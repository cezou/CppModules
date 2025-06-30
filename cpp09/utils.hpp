/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:27:22 by ple-guya          #+#    #+#             */
/*   Updated: 2025/04/13 13:44:56 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <sstream>


#ifndef PRINT
# define PRINT 0
#endif

#define DEFAULT_PORT 8080

/**
 * @brief Debug stream class that only outputs when DEBUG is enabled
 */
class DebugStream
{
public:
    template<typename T>
    DebugStream& operator<<(const T& value)
    {
        if (PRINT)
            std::cout << value;
        return *this;
    }
    
    DebugStream& operator<<(std::ostream& (*manip)(std::ostream&))
    {
        if (PRINT)
            std::cout << manip;
        return *this;
    }
};

extern DebugStream d_cout;

#define v(x) void(std::cerr << RED << x << RESET << std::endl)

// Définitions des codes ANSI pour la formatation du texte
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define ORANGE "\033[38;5;208m"
#define PINK "\033[38;5;198m"
#define R "\033[0m"
#define B "\033[1m"
#define BOLD "\033[1m"
#define D "\033[2m"
#define I "\033[3m"
#define U "\033[4m"
#define BLINK "\033[5m"
#undef RESET
#define RESET R

// Macro pour l'affichage conditionnel, utilisable comme une fonction
#define DEBUG_PRINT(arg)      \
	if (PRINT)            \
		std::cout << arg; 

/**
 * @brief Deletes a pointer and sets it to NULL
 * @tparam T Pointer type
 * @param ptr Reference to the pointer to delete
 */
template <typename T>
void deleteAndNull(T *&ptr)
{
    if (ptr)
    {
        delete ptr;
        ptr = NULL;
    }
}

/**
 * @brief Debug function to trace execution and identify where a segfault occurs
 * @param msg Optional additional message
 */
inline void s(const std::string &msg = "")
{
    static int count = 0;
    std::cout << "Squid #" << count++;
    if (!msg.empty())
        std::cout << " - " << msg;
    std::cout << std::endl;
}

/**
 * @brief Debug function to trace execution with a specific number
 * @param n Line number or custom identifier
 * @param msg Optional additional message
 */
inline void sn(int n, const std::string &msg = "")
{
    std::cout << "Squid #" << n;
    if (!msg.empty())
        std::cout << " - " << msg;
    std::cout << std::endl;
}

/**
 * @brief Exception class for handling errors in a red format
 * @details This class inherits from std::exception and provides a custom error message
 *          that is formatted with red color for better visibility in the console.
 * explicit is used to prevent implicit conversions from string to RedException.
 * exemple of why we use explicit:
 * RedException red = "This is a red error message"; // This will not compile
 */
class RedException : public std::exception
{
public:
    explicit RedException(const std::string& message) : _message(B RED "Error: " R RED + message + R) {}
    virtual ~RedException() throw() {}
    const char* what() const throw()
    {
        return _message.c_str();
    }

private:
    std::string _message;
};

class LineException : public RedException
{
public:
    explicit LineException(const std::string& message, size_t line_nb, const std::string& file = "") : 
        RedException(B U + file + ":" + convertLineNumber(line_nb) + R RED ": " + message.c_str()) {}
    virtual ~LineException() throw() {}

private:
    size_t _lineNumber;
    
    static std::string convertLineNumber(size_t value) {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
};



# define WHITESPACE " \t\n\r\f\v"
inline std::string trim(const std::string& str) 
{
    std::string result = str;
    result.erase(0, result.find_first_not_of(WHITESPACE));

    size_t last = result.find_last_not_of(WHITESPACE);
    if (last != std::string::npos)
        result.erase(last + 1);
    else
        result.clear();
    return result;
}

inline std::istream &getlineIt(std::istream& is, std::string& str, size_t *it)
{
	(*it)++;
	return std::getline(is, str);
}

inline std::istream &getLineTrimmed(std::istream& is, std::string& str, size_t *it)
{
	getlineIt(is, str, it);
	if (is)
		trim(str);
	return is;
}

#endif


