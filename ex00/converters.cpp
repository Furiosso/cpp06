#include "ScalarConverter.hpp"

void	convertPseudoliterals(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl
	<< "int: impossible" << std::endl
	<< "float: ";
	if (literal == "nanf" || literal == "nan")
		std::cout << "nanf" << std::endl << "double: nan" << std::endl;
	if (literal == "inff" || literal == "inf")
		std::cout << "inff" << std::endl << "double: inf" << std::endl;
	if (literal == "-inff" || literal == "-inf")
		std::cout << "-inff" << std::endl << "double: -inf" << std::endl;
	std::exit(0);
}

void	convertCharacter(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout<< "int: " << static_cast<int>(c) << std::endl
	<< "float: " << static_cast<float>(c) << ".0f" << std::endl
	<< "double: " << static_cast<double>(c) << ".0" << std::endl;
	std::exit(0);
}

void	convertInt(std::string& literal)
{
	std::cout << literal << " is int" << std::endl;
	std::exit(0);
}

void	convertFloat(std::string& literal)
{
	std::cout << literal << " is float" << std::endl;
	std::exit(0);
}

void	convertDouble(std::string& literal)
{
	std::cout << literal << " is double" << std::endl;
	std::exit(0);
}


void	printException()
{
	std::cout << "char: impossible" << std::endl
	<< "int: impossible" << std::endl
	<< "float: impossible" << std::endl
	<< "double: impossible" << std::endl;
	std::exit(0);
}