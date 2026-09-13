
#include "PmergeMe.hpp"

void PmergeMe::makePairs(std::vector<std::pair<int, int>> &pairs)
{
    for (size_t i = 0; i < _vector.size(); i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }
}

void PmergeMe::sortVector()
{
    std::vector<std::pair<int, int> > pairs;
    makePairs(pairs);
    
}

void PmergeMe::sortDeque()
{

}

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
        else if (num <= 0)
            return 0;
        _vector.push_back(num);
        _deque.push_back(num);
    }
    return 1;
}

PmergeMe::PmergeMe(char **av)
{
    if (!processInput(av))
            throw std::runtime_error("Error");
    std::cout << "Before : ";
    for (int i = 0; i < (int)_vector.size(); i++)
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