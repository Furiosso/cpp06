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
	std::cout << "char: ";
	if (n < 0 || n > 255)
		std::cout << "impossible";
	else if (n < 32 || n > 126)
		std::cout << "Non displayable";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'";
	std::cout << std::endl;
	std::cout << "int: " << n << std::endl
	<< std::fixed << std::setprecision(1) 
	<< "float: " << static_cast<float>(n) << "f" << std::endl
	<< "double: " << static_cast<double>(n) << std::endl;
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
	if (ln > std::numeric_limits<float>::max() || ln < -3.402823466f * pow(10.0f, 38.0f))
		printException();
	ss2 << literal;
	ss2 >> n;
	std::cout << "char: ";
	if (n < 0.0f || n > 255.0f)
		std::cout << "impossible";
	else if (n < 32.0f || n > 126.0f)
		std::cout << "Non displayable";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'";
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl
	<< "float: " << n;
	if (n - floor(n) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl
	<< "double: " << static_cast<double>(n);
	if (n - floor(n) == 0)
		std::cout << ".0";
	std::cout << std::endl;
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