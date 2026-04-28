#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator it1 = easyfind(v, 20);
        std::cout << "Vector'de bulundu: " << *it1 << std::endl;

        std::list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        std::list<int>::iterator it2 = easyfind(l, 3);
        std::cout << "List'te bulundu: " << *it2 << std::endl;

        easyfind(v, 99);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    return 0;
}