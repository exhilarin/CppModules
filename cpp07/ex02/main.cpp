#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "=== Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n=== Param constructor ===" << std::endl;
    Array<int> a(5);
    std::cout << "size: " << a.size() << std::endl;

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Out of bounds test ===" << std::endl;
    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> b(a);
    b[0] = 999;

    std::cout << "Original a[0]: " << a[0] << std::endl;
    std::cout << "Copy b[0]: " << b[0] << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> c;
    c = a;
    c[1] = 555;

    std::cout << "Original a[1]: " << a[1] << std::endl;
    std::cout << "Assigned c[1]: " << c[1] << std::endl;

    std::cout << "\n=== Const test ===" << std::endl;
    const Array<int> d(a);
    std::cout << "d[2]: " << d[2] << std::endl;

    return 0;
}
