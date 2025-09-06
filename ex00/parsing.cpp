#include "ScalarConverter.hpp"

static std::string&	trim(std::string& str, char c)
{
	std::size_t	len;
	std::size_t	i;

	len = str.length();
	i = 0;
	while (i < len && str[i] == c)
		i++;
	if (i < len)
		str = str.substr(i, len);
	len = str.length();
	i = len;
	while (i > 1 && str[i - 1] == c)
		i--;
	if (i > 1)
		str = str.substr(0, i);
	return (str);
}

void	parseLiteral(std::string& literal)
{
	std::size_t	len;
	std::size_t	i;
	bool	isFloat;

	if (literal == "nan" || literal == "inf" || literal == "-inf" || literal == "nanf" || literal == "inff" || literal == "-inff")
		convertPseudoliterals(literal);
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		convertCharacter(literal[0]);
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		convertCharacter(literal[1]);
	i = 0;
	len = literal.length();
	while (i < len && std::isspace(literal[i]))
		i++;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i >= len || !std::isdigit(literal[i]))
		printException();
	while (i < len && std::isdigit(literal[i]))
		i++;
	while (i < len && std::isspace(literal[i]))
		i++;
	isFloat = false;
	if (i == len)
		convertInt(trim(trim(literal, ' '), '+'));
	if (literal[i] == '.')
	{
		i++;
		while (i < len && std::isdigit(literal[i]))
			i++;
		if (literal[i] == 'f')
		{
			i++;
			isFloat = true;
		}
		while (i < len && std::isspace(literal[i]))
			i++;
		if (i < len)
			printException();
		if (isFloat)
			convertFloat(trim(trim(literal, ' '), '+'));
		convertDouble(trim(trim(literal, ' '), '+'));
	}
	printException();
}
