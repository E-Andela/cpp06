#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>
// #include <cstdlib>

Base* generate()
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(time(NULL));
		seeded = true;
	}
	int rand = std::rand();

	switch (rand % 3)
	{
	case 0:
		std::cout << "Generated A" << std::endl;
		return new A();
		break;
	case 1:
		std::cout << "Generated B" << std::endl;
		return new B();
		break;
	default:
		std::cout << "Generated C" << std::endl;
		return new C();
		break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e) { }
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e) { }
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e) { }	

}

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		Base *basePtr = generate();
		std::cout << "Identify ptr: ";
		identify(basePtr);
		std::cout << "Identify ref: ";
		identify(*basePtr);
		std::cout << std::endl;
	}
}