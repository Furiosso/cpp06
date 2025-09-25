#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <sstream>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <iomanip>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
	public:
		~ScalarConverter();
		static void	convert(std::string literal);
};

void	parseLiteral(std::string& literal);
bool	checkConversionF(const std::string& literal, float n);
bool	checkConversionD(const std::string& literal, double n);
void	convertPseudoliterals(const std::string& literal);
void	convertCharacter(char c);
void	convertInt(std::string& literal);
void	convertFloat(std::string& literal);
void	convertDouble(std::string& literal);
int		countCiphers(const std::string& literal);
void	printException();

#endif
