#include "RPN.hpp"

/**
 * @brief Constructor for RPN class
 * @details The constructor takes a string argument representing the RPN expression.
 * It parses the expression, validates the characters, and performs the operations.
 */
RPN::RPN(std::string args) : _operation(args)
{
	std::string::iterator it = args.begin();
	while (it != args.end())
	{
		while (it != args.end() && isspace(*it))
			it++;
		if (it == args.end())
			break;
		if (VALID_CHARACTERS.find(*it) == std::string::npos
			|| (it+1 != args.end() && !isspace(*(it+1))))
		{
			throw ArgException("Invalid character: ", _operation, std::distance(it, args.end()));
		}
		if (isdigit(*it))
			_stack.push(*it - '0');
		else
			updateResult(it, args.end());
		++it;
	}
	if (_stack.empty())
		throw RedException("No Expression");
	if (_stack.size() > 1)
		throw RedException("Bad Expression: " B "Not enough operators");
	std::cout << B "Result: " GREEN << _stack.top() << R << std::endl;
}


/**
 * @brief Updates the result stack
 * @details The function updates the top of the stack with 
 * the result of the operation of the two topmost elements.
 */
void RPN::updateResult(std::string::iterator it, std::string::iterator end)
{
	if (_stack.size() < 2)
		throw ArgException("Not enough numbers in stack to perform operation: ", _operation, std::distance(it, end));
	// printStack();
	int nb = _stack.top();
	_stack.pop();
	// std::cout << _stack.top() << " " << *it << " " << nb << std::endl;
	switch (*it)
	{
		case '+':
			_stack.top() += nb;
			break;
		case '-':
			_stack.top() -= nb;
			break;
		case '*':
			_stack.top() *= nb;
			break;
		case '/':
			if (nb == 0)
				throw ArgException("Division by zero is forbidden ", _operation, std::distance(it, end));
			_stack.top() /= nb;
	}
}


void RPN::printStack()
{
	std::cout << "Stack: ";
	for (std::stack<int> tmp = _stack; !tmp.empty(); tmp.pop())
			std::cout << tmp.top() << " ";
	std::cout << std::endl;
}