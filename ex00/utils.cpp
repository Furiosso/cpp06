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
