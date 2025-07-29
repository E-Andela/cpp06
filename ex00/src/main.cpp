#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <limits>

int main(int argc, char* argv[])
{
	try
	{
		if (argc == 2)
			ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}