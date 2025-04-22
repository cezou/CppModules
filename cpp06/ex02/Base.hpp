#ifndef BASE_HPP
# define BASE_HPP

# include "../Utils.hpp" // Keep for colors/macros if used in main.cpp via Base.hpp
# undef B

class Base
{
	public:
		virtual ~Base(); // Public virtual destructor
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

// Function declarations
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
