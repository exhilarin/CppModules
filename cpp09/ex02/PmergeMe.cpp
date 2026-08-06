
#include "PmergeMe.hpp"

int PmergeMe::processInput(char **av)
{
    int num;
    char c;

    for (int i = 1; av[i]; i++)
    {
        std::stringstream ss(av[i]);
        ss >> num;
        if (ss.fail())
            return 0;
        else if (ss >> c)
            return 0;
        else if (num < 0 || num > MAX_INT)
            return 0;
        for (int j = i + 1; av[j]; j++)
        {
            if (static_cast<std::string>(av[i]) == static_cast<std::string>(av[j]))
                return 0;
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }
    return 1;
}

PmergeMe::PmergeMe(char **av)
{
    if (!processInput(av))
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << "Before : ";
    for (int i = 0; av[i]; i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::sort(_vector.begin(), _vector.end());
    std::cout << "After : ";
    for (int i = 0; av[i]; i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

/*--------------Orthodox----------------*/
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}