
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <cerrno>
# include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static bool handlePseudoLiteral(const std::string &literal);
        static bool handleCharLiteral(const std::string &literal);
        static bool handleNumericLiteral(const std::string &literal);
    public:
        static void convert(std::string literal);
};

#endif