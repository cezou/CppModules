# pragma once

# include <iostream>
# include <string>
# include "../utils.hpp"
# include "algorithm"
# include "stack"
# define VALID_CHARACTERS std::string("0123456789+-*/")

class RPN
{
public:
	RPN(std::string args);
	~RPN() {};

	void updateResult(std::string::iterator it, std::string::iterator end);
	void printStack();

	class ArgException : public std::exception
	{
	public:
		explicit ArgException(const std::string& message, const std::string& operation, size_t pos = 0) : 
			_message(B RED "Error: " R + message + operation + "\n")
		{
			size_t len = _message.length();
			std::ostringstream oss;
			oss << pos;
			for (size_t i = 0; i < len - pos - std::string(B RED R).length() - 1; i++)
				_message += " ";
			_message +=  RED BOLD "^" R;
		}
		virtual ~ArgException() throw() {}
		const char* what() const throw()
		{
			return _message.c_str();
		}

	private:
		std::string _message;
	};
	
private:
	std::stack<int> _stack;
	std::string _operation;

	// Not used but respects the rule of 5
	RPN() {};
	RPN(const RPN &c) {(void)c;};
	RPN & operator=(const RPN &a) {(void)a; return *this;};

};
