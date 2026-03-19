
#include "whatever.hpp"

int main()
{
    std::cout << "------- Testing with int -------" << std::endl;
    int a = 6;
    int b = 1;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;

    std::cout << "--- Testing with std::string ---" << std::endl;
    std::string c = "Alexandra";
    std::string d = "İlyas";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}
