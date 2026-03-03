
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool PseudoLiteral(std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char   : imposiible" << std::endl;
        std::cout << "int    : imposiible" << std::endl;
        std::cout << "float  : " << literal << std::endl;

        std::string dbl = literal.substr(0, literal.size() - 1);
        std::cout << "double : " << dbl << std::endl;
        return true;
    }
    else if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char   : imposiible" << std::endl;
        std::cout << "int    : imposiible" << std::endl;
        std::cout << "float  : " << literal << "f" << std::endl;
        std::cout << "double : " << literal << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert(std::string literal)
{
    if(PseudoLiteral(literal))
        return ;
}
