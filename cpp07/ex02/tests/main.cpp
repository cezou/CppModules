#include <Array.hpp>

#define MAX_VAL 750

void printHeader(const std::string& title) {
	std::cout << std::endl << CYAN << title << R << std::endl;
}

void testDeepCopy(unsigned int n) {
	printHeader("Deep Copy Test");
	Array<int> a(n);

	for (unsigned int i = 0; i < n; ++i)
		a[i] = static_cast<int>(i * 10);

	Array<int> b = a;
	Array<int> c;
	c = a;

	std::cout << "Original a[0]: " << a[0] << ", b[0]: " << b[0] << ", c[0]: " << c[0] << std::endl;
	a[0] = 999;
	std::cout << "Modified a[0]: " << a[0] << ", b[0]: " << b[0] << ", c[0]: " << c[0] << std::endl;

	if (b[0] == 999 || c[0] == 999)
		std::cout << RED "Error: Copy or assignment was not deep!" R << std::endl;
	else
		std::cout << GREEN "OK: Copy and assignment appear deep." R << std::endl;
}

void testAccess(unsigned int n) {
	printHeader("Access Test");
	Array<int> arr(n);

	std::cout << "Array size: " << arr.size() << std::endl;
	if (n > 0) {
		arr[0] = 123;
		std::cout << "Write/Read arr[0]: " << arr[0] << std::endl;
		if (arr[0] != 123)
			std::cout << RED "Error: Read/Write failed!" R << std::endl;
		else
			std::cout << GREEN "OK: Read/Write successful." R << std::endl;
	} else {
		std::cout << "Skipping read/write test for zero size array." << std::endl;
	}

	std::cout << "Testing out-of-bounds access..." << std::endl;
	try {
		arr[n] = 0;
		std::cout << RED "Error: Accessing index " << n << " did not throw!" R << std::endl;
	} catch (const Array<int>::IndexOutOfBoundsException& e) {
		std::cout << GREEN "OK: " R << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED "Error: Unexpected exception: " R << e.what() << std::endl;
	}

	try {
		int x = arr[-1]; 
		(void)x; 
		std::cout << RED "Error: Accessing index -1 did not throw!" R << std::endl;
	} catch (const Array<int>::IndexOutOfBoundsException& e) {
		std::cout << GREEN "OK: " R << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED "Error: Unexpected exception: " R << e.what() << std::endl;
	}
}

void testDefaultConstructor() {
	printHeader("Default Constructor Test");
	Array<int> empty;
	std::cout << "Default constructed array size: " << empty.size() << std::endl;
	if (empty.size() != 0)
		std::cout << RED "Error: Default constructor size is not 0!" R << std::endl;
	else
		std::cout << GREEN "OK: Default constructor size is 0." R << std::endl;

	std::cout << "Testing out-of-bounds access on default array..." << std::endl;
	try {
		empty[0] = 0;
		std::cout << RED "Error: Accessing index 0 on default array did not throw!" R << std::endl;
	} catch (const Array<int>::IndexOutOfBoundsException& e) {
		std::cout << GREEN "OK: " R << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED "Error: Unexpected exception: " R << e.what() << std::endl;
	}
}

int main(int ac, char **av) {
	long inputVal = 750;

	if (ac > 1) 
	{
		inputVal = std::atol(av[1]);
		if (!inputVal)
			return (v("Error: Invalid input. Please enter a valid number."), 1);
		if (inputVal < 0)
			return (v("Error: Number of elements cannot be negative."), 1);
		if (inputVal > MAX_VAL)
			return (v("Error: Number of elements (" B << inputVal << R RED ") exceeds MAX_VAL (" B << MAX_VAL << R RED")." R), 1);
	}
	unsigned int n = static_cast<unsigned int>(inputVal);
	std::cout << BOLD "Testing Array with size: " << n << RESET << std::endl;
	testDefaultConstructor();
	testDeepCopy(n);
	testAccess(n);
}
