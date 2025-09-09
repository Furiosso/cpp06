#include "ScalarConverter.hpp"

int	countCiphers(const std::string& literal)
{
	int	i;
	int j;
	int	len;

	i = 0;
	len = literal.length();
	while (i < len && literal[i] != '.')
		i++;
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