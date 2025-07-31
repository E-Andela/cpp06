#include "../inc/ScalarConverter.hpp"
#include <limits>
#include <iostream>
#include <fstream>

void testChars()
{
	for (int c = std::numeric_limits<char>::min(); c <= std::numeric_limits<char>::max(); ++c)
	{
		char ch = static_cast<char>(c);
		std::cout << "Char going in: " << c << std::endl;
		std::string str = std::string(1, ch);
		std::cout << str << std::endl;
		ScalarConverter::convert(str);
		std::cout << std::endl;
	}
}

void helpTestFloat(float value, const char* overrideToString)
{
	std::string str;
	if (overrideToString)
		str = overrideToString;
	else
		str = std::to_string(value);
	std::cout << value << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

void testFloat()
{
	helpTestFloat(5.0f, nullptr); // Simple positive
    helpTestFloat(-5.0f, nullptr); // Simple negative
    helpTestFloat(0.0f, nullptr); // Zero
    helpTestFloat(-0.0f, "-0.0"); // Negative zero
    helpTestFloat(1.0f, nullptr); // One
    helpTestFloat(-1.0f, nullptr); // Negative one
    helpTestFloat(std::numeric_limits<float>::min(), "1.17549e-38"); // Smallest positive normalized
    helpTestFloat(-std::numeric_limits<float>::min(), "-1.17549e-38"); // Smallest negative normalized
    helpTestFloat(std::numeric_limits<float>::max(), "3.40282e+38"); // Largest positive
    helpTestFloat(-std::numeric_limits<float>::max(), "-3.40282e+38"); // Largest negative
    helpTestFloat(std::numeric_limits<float>::infinity(), "inf"); // Positive infinity
    helpTestFloat(-std::numeric_limits<float>::infinity(), "-inf"); // Negative infinity
    helpTestFloat(std::numeric_limits<float>::signaling_NaN(), "nan"); // Signaling NaN
    helpTestFloat(3.14159f, "3.14159f"); // Pi
    helpTestFloat(2.71828f, "2.71828f"); // e
    helpTestFloat(1e-40f, "1e-40f"); // Very small subnormal
    helpTestFloat(1e+38f, nullptr); // Very large
    helpTestFloat(-1e+38f, nullptr); // Very large negative
    helpTestFloat((128696.0f / 3874.0f), nullptr); // Arbitrary value
}

void helpTestDouble(double value, const char* overrideToString)
{
    std::string str;
    if (overrideToString)
        str = overrideToString;
    else
        str = std::to_string(value);
    std::cout << value << std::endl;
    ScalarConverter::convert(str);
    std::cout << std::endl;
}

void testDouble()
{
    helpTestDouble(5.0, nullptr); // Simple positive
    helpTestDouble(-5.0, nullptr); // Simple negative
    helpTestDouble(0.0, nullptr); // Zero
    helpTestDouble(-0.0, "-0.0"); // Negative zero
    helpTestDouble(1.0, nullptr); // One
    helpTestDouble(-1.0, nullptr); // Negative one
    helpTestDouble(std::numeric_limits<double>::min(), "2.22507e-308"); // Smallest positive normalized
    helpTestDouble(-std::numeric_limits<double>::min(), "-2.22507e-308"); // Smallest negative normalized
    helpTestDouble(std::numeric_limits<double>::max(), "1.79769e+308"); // Largest positive
    helpTestDouble(-std::numeric_limits<double>::max(), "-1.79769e+308"); // Largest negative
    helpTestDouble(std::numeric_limits<double>::infinity(), "inf"); // Positive infinity
    helpTestDouble(-std::numeric_limits<double>::infinity(), "-inf"); // Negative infinity
    helpTestDouble(std::numeric_limits<double>::signaling_NaN(), "nan"); // Signaling NaN
    helpTestDouble(3.141592653589793, "3.141592653589793"); // Pi
    helpTestDouble(2.718281828459045, "2.718281828459045"); // e
    helpTestDouble(1e-320, "1e-320"); // Very small subnormal
    helpTestDouble(1e+308, nullptr); // Very large
    helpTestDouble(-1e+308, nullptr); // Very large negative
    helpTestDouble((128696.0 / 3874.0), nullptr); // Arbitrary value
}

void helpTestInt(int value, const char* overrideToString)
{
    std::string str;
    if (overrideToString)
        str = overrideToString;
    else
        str = std::to_string(value);
    std::cout << value << std::endl;
    ScalarConverter::convert(str);
    std::cout << std::endl;
}

void testInt()
{
    helpTestInt(0, nullptr); // Zero
    helpTestInt(1, nullptr); // One
    helpTestInt(-1, nullptr); // Negative one
    helpTestInt(42, nullptr); // Arbitrary positive
    helpTestInt(-42, nullptr); // Arbitrary negative
    helpTestInt(std::numeric_limits<int>::max(), nullptr); // Largest positive int
    helpTestInt(std::numeric_limits<int>::min(), nullptr); // Smallest negative int
    helpTestInt(127, nullptr); // Max ASCII value
    helpTestInt(255, nullptr); // Max unsigned char value (may overflow)
    helpTestInt(-128, nullptr); // Min signed char value
    helpTestInt(2147483647, "2147483647"); // INT_MAX explicitly
    helpTestInt(-2147483648, "-2147483648"); // INT_MIN explicitly
    helpTestInt(1000000, nullptr); // Large positive
    helpTestInt(-1000000, nullptr); // Large negative
}

int main()
{
	std::ofstream charFile("char-test");
	std::ofstream intFile("int-test");
	std::ofstream floatFile("float-test");
	std::ofstream doubleFile("double-test");

	std::streambuf* coutbuf = std::cout.rdbuf();
	
	std::cout.rdbuf(charFile.rdbuf());
	testChars();

	std::cout.rdbuf(intFile.rdbuf());
	testInt();

	std::cout.rdbuf(floatFile.rdbuf());
	testFloat();

	std::cout.rdbuf(doubleFile.rdbuf());
	testDouble();
	
	std::cout.rdbuf(coutbuf);
}