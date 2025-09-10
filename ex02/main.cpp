#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base*	generate()
{
	int		i;

	i = rand() % 3;
	switch (i)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

static void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's an A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "It's an B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "It's an C" << std::endl;
}

static void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "It's an A" << std::endl;
	}
	catch (...)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "It's a B" << std::endl;
		}
		catch (...)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "It's a C" << std::endl;
			}
			catch (...) {}
		}
	}
}

int	main()
{
	srand(time(NULL));
	Base* ptr = generate();

	std::cout << "Pointer: ";
	identify(ptr);
	std::cout << "Reference: ";
	identify(*ptr);
	delete ptr;
}