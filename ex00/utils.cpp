#include "ScalarConverter.hpp"

int	countCiphers(const std::string& literal)
{
	int	i;
	int j;
	int	len;

	len = literal.length();
	i = literal.find('.');
	if (i == len)
		return 1;
	i++;
	j = 0;
	while (i < len)
	{
		i++;
		j++;
	}
	return j;
}

bool	checkConversionF(const std::string& literal, float n)
{
	std::stringstream	ss;
	size_t				len[2];
	std::string			str;

	ss << std::fixed << std::setprecision(countCiphers(literal)) << n;
	str = ss.str();
	len[0] = str.length() - 1;
	len[1] = literal.length() - 1;
	while (len[0] > len[1] && str[len[0]] == '0')
		len[0]--;
	if (str[len[0]] == '.' && literal[len[1]] != '.')
		len[0]--;
	if (len[0] != len[1])
		return false;
	while (len[0] > 0)
	{
		if (literal[len[1]] != str[len[0]])
			return false;
		len[1]--;
		len[0]--;
	}
	if (literal[0] != str[0])
		return false;
	return true;
}

bool	checkConversionD(const std::string& literal, double n)
{
	std::stringstream	ss;
	size_t				len[2];
	std::string			str;

	ss << std::fixed << std::setprecision(countCiphers(literal)) << n;
	str = ss.str();
	len[0] = str.length() - 1;
	len[1] = literal.length() - 1;
	while (len[0] > len[1] && str[len[0]] == '0')
		len[0]--;
	if (str[len[0]] == '.' && literal[len[1]] != '.')
		len[0]--;
	if (len[0] != len[1])
		return false;
	while (len[0] > 0)
	{
		if (literal[len[1]] != str[len[0]])
			return false;
		len[1]--;
		len[0]--;
	}
	if (literal[0] != str[0])
		return false;
	return true;
}