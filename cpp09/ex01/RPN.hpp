# pragma once

# include <iostream>
# include <string>
# include "../utils.hpp"
# include "algorithm"
# include "stack"

class RPN
{
public:
	RPN(std::string operation);
	~RPN() {};

	void checkArguments(std::string args);
	class ArgException : public std::exception
	{
	public:
		explicit ArgException(const std::string& message, const std::string& operation, size_t pos = 0) : 
			_message(B RED "Error: " R + message + " in " + operation + "\n")
		{
			std::ostringstream oss;
			oss << pos;
			for (size_t i = 0; i < pos + message.length() + operation.length() + 6; i++)
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
	std::stack<int> stack;
	std::string _operation;

	// Not used but respects the rule of 5
	RPN() {};
	RPN(const RPN &c) {(void)c;};
	RPN & operator=(const RPN &a) {(void)a; return *this;};

};
