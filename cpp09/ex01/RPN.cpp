#include "RPN.hpp"




RPN::RPN(std::string operation) : _operation(operation)
{
	checkArguments(operation);
}


// Il n'il doit y a voir que des charactères compris dans [0123456789+-*/]
#define VALID_CHARACTERS "0123456789+-*/"
void RPN::checkArguments(std::string args)
{
	// split par whitespace, regarder si a l'intérieur il y a bien que [0123456789+-*/]
	std::string::iterator it = args.begin();
	while (it != args.end())
	{
		// split par whitespace
		while (it != args.end() && *it == ' ')
			it++;
			// ou qu'il n'est pas suivi par un espace
		if (std::find(VALID_CHARACTERS, VALID_CHARACTERS + 10, *it) == VALID_CHARACTERS + 10 || (it+1 != args.end() && !isspace(*(it+1))))
		{
			std::ostringstream oss;
			oss << std::distance(args.begin(), it);
			std::string str = oss.str();
			throw ArgException("Invalid character", _operation, std::distance(args.begin(), it));
		}
		++it;
	}
}
