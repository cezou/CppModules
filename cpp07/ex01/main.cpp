#include "iter.hpp"

int main()
{
	testIter((int[]){1, -2, 3, 4, 5}, "int");
	testIter((std::string []){"Squid", "Game", "!"}, "string");
	testIter((char[]){'a', 'b', 'c', 'd'}, "char");
	testIter((float[]){1.1f, 2.2f, 3.3f}, "float");
	testIter((double[]){1.1, 2.2, 3.3}, "double");
	testIter((bool[]){true, false, true}, "bool");
	testIter((unsigned int[]){1, 2, 3, 4, 5}, "unsigned int");
	testIter((long[]){1, 2, 3, 4, 5}, "long");
	testIter((short[]){1, 2, 3, 4, 5}, "short");
	testIter((long long[]){1, 2, 3, 4, 5}, "long long");
	testIter((unsigned char[]){'a', 'b', 'c', 'd'}, "unsigned char");
	testIter((unsigned short[]){1, 2, 3, 4, 5}, "unsigned short");
	testIter((const int[]){10, 20, 30}, "const int");
}
