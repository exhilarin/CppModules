
#include "PmergeMe.hpp"

static std::vector<int> fordJohnson(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] < input[i + 1])
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        else
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
    }

    std::vector<int> large;

    for (size_t i = 0; i < pairs.size(); i++)
        large.push_back(pairs[i].second);

    std::vector<int> sortedLarge = fordJohnson(large);

    std::vector<int> mainChain = sortedLarge;

    if (!pairs.empty())
        mainChain.insert(mainChain.begin(), pairs[0].first);

    std::vector<int> pend;

    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].first);

    

}

void PmergeMe::sortVector()
{
    // Make Pair
    std::vector<std::pair<int, int> > pairs;
    int odd = -1;

    size_t i = 0;
    for (; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }

    if (i < _vector.size())
        odd = _vector[i];

    // Fill Main Chain and Pend
    std::vector<int> mainChain;
    std::vector<int> pend;

    if (!pairs.empty())
    {
        mainChain.push_back(pairs[0].first);

        for (size_t j = 0; j < pairs.size(); j++)
        {
            mainChain.push_back(pairs[j].second);
            if (j > 0)
                pend.push_back(pairs[j].first);
        }
    }

    // Recursive Sorting
    std::vector<int> large;
    for (size_t i = 0; i < pairs.size(); i++)
        large.push_back(pairs[i].second);    
    

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
        else if (num < 0)
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