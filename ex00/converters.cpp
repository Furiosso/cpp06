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
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout<< "int: " << static_cast<int>(c) << std::endl
	<< "float: " << static_cast<float>(c) << ".0f" << std::endl
	<< "double: " << static_cast<double>(c) << ".0" << std::endl;
	std::exit(0);
}

void	convertInt(std::string& literal)
{
	std::stringstream	ss1;
	std::stringstream	ss2;
	long long			ln;
	int					n;

	ss1 << literal;
	ss1 >> ln;
	if (ln > std::numeric_limits<int>::max() || ln < std::numeric_limits<int>::min())
		printException();
	ss2 << literal;
	ss2 >> n;
	if (n < 32 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
	std::exit(0);
}

void	convertFloat(std::string& literal)
{
	std::stringstream	ss1;
	std::stringstream	ss2;
	long double			ln;
	float				n;

	ss1 << literal;
	ss1 >> ln;
	if (ln > std::numeric_limits<float>::max() || ln < std::numeric_limits<float>::min())
		printException();
	ss2 << literal;
	ss2 >> n;
	if (n < 32.0f || n > 126.0f)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << n << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
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