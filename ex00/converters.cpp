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
	std::cout << "char: '" << c << "'" << std::endl
	<< "int: " << static_cast<int>(c) << std::endl
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
	if (n < 0 || n > 127)
		std::cout << "impossible";
	else if (n < 32 || n > 126)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(n) << "'";
	std::cout << std::endl;
	std::cout << "int: " << n << std::endl << std::fixed << std::setprecision(1) << "float: ";
	if (!checkConversionF(literal, static_cast<float>(n)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: ";
	if (!checkConversionD(literal, static_cast<double>(n)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(n) << std::endl;
	std::exit(0);
}

void	convertFloat(std::string& literal)
{
	std::stringstream	ss1;
	std::stringstream	ss2;
	long double			ln;
	float				n;
	int					fractionalCount;

	ss1 << literal;
	ss1 >> ln;
	if (ln > std::numeric_limits<float>::max()
		|| ln < -std::numeric_limits<float>::max())
		printException();
	ss2 << literal;
	ss2 >> n;
	if (!checkConversionF(literal, n))
		printException();
	fractionalCount = countCiphers(literal);
	if (std::fabs(n) - std::abs(static_cast<int>(n)) == 0)
		fractionalCount = 1;
	std::cout << "char: ";
	if (n < 0.0f || n > 127.0f)
		std::cout << "impossible";
	else if (n < 32.0f || n > 126.0f)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(n) << "'";
	std::cout << std::endl << "int: ";
	if (static_cast<double>(n) > std::numeric_limits<int>::max()
		|| static_cast<double>(n) < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(n);
	std::cout << std::endl
	<< std::fixed << std::setprecision(fractionalCount) << "float: " << n << "f" << std::endl
	<< "double: " << static_cast<double>(n) << std::endl;
	std::exit(0);
}

void	convertDouble(std::string& literal)
{
	std::stringstream	ss1;
	std::stringstream	ss2;
	long double			ln;
	double				n;
	int					fractionalCountD;
	int					fractionalCountF;

	ss1 << literal;
	ss1 >> ln;
	if (ln > std::numeric_limits<double>::max()
		|| ln < -std::numeric_limits<double>::max())
		printException();
	ss2 << literal;
	ss2 >> n;
	if (!checkConversionD(literal, n))
		printException();
	fractionalCountF = fractionalCountD = countCiphers(literal);
	if (std::fabs(n) - std::abs(static_cast<int>(n)) == 0)
		fractionalCountD = 1;
	if (std::fabs(static_cast<float>(n)) - std::abs(static_cast<int>(n)) == 0)
		fractionalCountF = 1;
	std::cout << "char: ";
	if (n < 0.0 || n > 127.0)
		std::cout << "impossible";
	else if (n < 32.0 || n > 126.0)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(n) << "'";
	std::cout << std::endl << "int: ";
	if (n > std::numeric_limits<int>::max()
		|| n < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(n);
	std::cout << std::endl
	<< std::fixed << std::setprecision(fractionalCountF) << "float: ";
	if (n > std::numeric_limits<float>::max()
		|| n < -std::numeric_limits<float>::max()
		|| !checkConversionF(literal, static_cast<float>(n)))
		std::cout << "impossible";
	else
		std::cout << static_cast<float>(n) << "f";
	std::cout << std::setprecision(fractionalCountD) << std::endl
	<< "double: " << n << std::endl;
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