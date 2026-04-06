
#include <iostream>
#include <string.h>
#include "iter.hpp"

template<typename T>
void print(const T &value)
{
    std::cout << value << " ";
}

template<typename T>
void increment(T &value)
{
    value++;
}

int main()
{
    std::cout << "----- INT TEST -----" << std::endl;
    int intArr[] = {1, 2, 3, 4};
    unsigned int intSize = sizeof(intArr)/sizeof(intArr[0]);

    std::cout << "Before: ";
    iter(intArr, intSize, print<int>);
    std::cout << std::endl;

    iter(intArr, intSize, increment<int>);

    std::cout << "After increment: ";
    iter(intArr, intSize, print<int>);
    std::cout << std::endl << std::endl;

    std::cout << "----- STRING TEST -----" << std::endl;
    std::string strArr[] = {"Alexandra <3", "İlyas"};
    unsigned int strSize = sizeof(strArr)/sizeof(strArr[0]);

    std::cout << "Strings: ";
    iter(strArr, strSize, print<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "----- CONST TEST -----" << std::endl;
    const int constArr[] = {10, 20, 30};
    unsigned int constSize = sizeof(constArr)/sizeof(constArr[0]);

    std::cout << "Const ints: ";
    iter(constArr, constSize, print<const int>);
    std::cout << std::endl;

    return 0;
}