#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <limits>
#include <cmath>

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
}

static void printChar(double value)
{
	std::cout << "char: ";

	char c = static_cast<char>(value);

	if (value < 0 || value > 255 || std::isnan(value))
	{
		std::cout << "impossible" << std::endl;
	}
	else if (std::isprint(c))
	{
		std::cout << c << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

static void printInt(double value)
{
	std::cout << "int: ";

	if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (value > static_cast<double>(std::numeric_limits<float>::max()) || value < 0 - static_cast<double>(std::numeric_limits<float>::max()))
	{
		if (!std::isinf(value))
		{
			std::cout << "impossible" << std::endl;
			return;
		}
	}
	std::cout << static_cast<float>(value);
	if (value == static_cast<int>(value))
	{
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;

}

static void printDouble(double value)
{
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
	{
		std::cout << ".0";
	}
	std::cout << std::endl;
}

static bool isEscapeSequence(const std::string& literal, char& outChar)
{
	if (literal.length() == 2 && literal[0] == '\\') {
		switch (literal[1]) {
			case '0': outChar = '\0'; return true;
			case 'a': outChar = '\a'; return true;
			case 'b': outChar = '\b'; return true;
			case 't': outChar = '\t'; return true;
			case 'n': outChar = '\n'; return true;
			case 'v': outChar = '\v'; return true;
			case 'f': outChar = '\f'; return true;
			case 'r': outChar = '\r'; return true;
			case '\\': outChar = '\\'; return true;
			case '"': outChar = '"'; return true;
			case '\'': outChar = '\''; return true;
			default: return false;
		}
	}
	return false;
}

void ScalarConverter::convert(const std::string &literal)
{
	double value;
	try {
		value = std::stod(literal);
	} 
	catch (const std::invalid_argument &e)
	{
		char escChar;
		if (literal.length() == 1)
		{
			value = static_cast<double>(literal[0]);
		}
		else if (isEscapeSequence(literal, escChar))
		{
			value = static_cast<double>(escChar);
		}
		else
		{
			printImpossible();
			return;
		}
	}
	catch (const std::out_of_range &e)
	{
		printImpossible();
		return;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

ScalarConverter::ScalarConverter()
{
	#ifdef DEBUG
	std::cout << "ScalarConverter default constructor called" << std::endl;
	#endif
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	#ifdef DEBUG
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	#endif
	(void)other; // To avoid unused parameter warning
}
ScalarConverter::~ScalarConverter()
{
	#ifdef DEBUG
	std::cout << "ScalarConverter destructor called" << std::endl;
	#endif
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	#ifdef DEBUG
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		// Copy the data from other to this
	}
	return *this;
}