
#include "ScalarConverter.hpp"

bool ScalarConverter::handlePseudoLiteral(const std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return true;
    }
    else if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return true;
    }
    return false;
}

static void printAll(char c, int i, float f, double d, int charFlag, bool intImpossible)
{
    if (charFlag == 0)
        std::cout << "char: '" << c << "'" << std::endl;
    else if (charFlag == 1)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (intImpossible)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::handleCharLiteral(const std::string &literal)
{
    if (literal.length() != 1)
        return false;

    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    int charFlag = (c >= 32 && c <= 126) ? 0 : 1;
    bool intImpossible = false;

    printAll(c, i, f, d, charFlag, intImpossible);
    return true;
}

bool ScalarConverter::handleNumericLiteral(const std::string &literal)
{
    if (literal.empty())
        return false;

    errno = 0;
    double value;

    if (literal[literal.size() - 1] == 'f')
        value = std::strtof(literal.c_str(), 0);
    else
        value = std::strtod(literal.c_str(), 0);

    if (errno == ERANGE)
    {
        printAll(0, 0, 0.0f, 0.0, 2, true);
        return false;
    }

    char c = static_cast<char>(value);
    int i = static_cast<int>(value);
    float f = static_cast<float>(value);
    double d = value;

    int charFlag;
    if (value < 0 || value > 127)
        charFlag = 2;
    else if (c < 32 || c > 126)
        charFlag = 1;
    else
        charFlag = 0;

    bool intImpossible = (value < INT_MIN || value > INT_MAX);

    printAll(c, i, f, d, charFlag, intImpossible);
    return true;
}

void ScalarConverter::convert(std::string literal)
{
    if (handlePseudoLiteral(literal))
        return;
    if (handleCharLiteral(literal))
        return;
    if (handleNumericLiteral(literal))
        return;

    std::cout << "Invalid input!" << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}
