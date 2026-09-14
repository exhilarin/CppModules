
#include "PmergeMe.hpp"

static void seperatePair(std::vector<std::pair<int, int> > &pairs, std::vector<int> &large, std::vector<int> &small)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        small.push_back(pairs[i].first);
        large.push_back(pairs[i].second);
    }
}

static void makePairs(std::vector<int> &_vector, std::vector<std::pair<int, int> > &pairs, int &odd)
{
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }
    if (_vector.size() % 2 != 0)
        odd = _vector[_vector.size() - 1];
}

static void makeJacobsthalOrder(std::vector<size_t> &order, size_t size)
{
    if (size == 0)
        return ;

    order.push_back(0);
    size_t previous = 1;
    size_t previous_previous = 1;
    while (size > previous)
    {
        size_t current = previous + 2 * previous_previous;
        size_t i = current;
        if (i > size)
            i = size;
        while (i > previous)
        {
            order.push_back(i - 1);
            i--;
        }
        previous_previous = previous;
        previous = current;
    }
}

std::vector<int> PmergeMe::sortVector(std::vector<int> input)
{
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> large;
    std::vector<int> small;
    std::vector<int> main_chain;
    std::vector<size_t> order;
    int odd = -1;
    
    makePairs(input, pairs, odd);
    seperatePair(pairs, large, small);
    main_chain = sortVector(large);
    makeJacobsthalOrder(order, small.size());
    if (odd != -1)
    {
        std::vector<int>::iterator pos;

        pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd);
        main_chain.insert(pos, odd);
    }
    return main_chain;
}

// void PmergeMe::sortDeque()
// {

// }

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

const std::vector<int> PmergeMe::getVector()
{
    return _vector;
}

const std::deque<int> PmergeMe::getDeque()
{
    return _deque;
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