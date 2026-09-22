#include "PmergeMe.hpp"

template <typename T>
static void seperatePair(const std::vector<std::pair<int, int> > &pairs, T &small, T &large)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        small.push_back(pairs[i].first);
        large.push_back(pairs[i].second);
    }
}

template <typename T>
static void makePairs(const T &_container, std::vector<std::pair<int, int> > &pairs, int &odd)
{
    for (size_t i = 0; i + 1 < _container.size(); i += 2)
    {
        if (_container[i] < _container[i + 1])
            pairs.push_back(std::make_pair(_container[i], _container[i + 1]));
        else
            pairs.push_back(std::make_pair(_container[i + 1], _container[i]));
    }
    if (_container.size() % 2 != 0)
        odd = _container[_container.size() - 1];
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

template <typename T>
static T mergeInsertSort(const T &input)
{
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;
    T large;
    T small;
    T main_chain;
    std::vector<size_t> order;
    int odd = -1;

    makePairs(input, pairs, odd);
    seperatePair(pairs, small, large);
    main_chain = mergeInsertSort(large);
    makeJacobsthalOrder(order, small.size());

    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = order[i];
        typename T::iterator bound;
        bound = std::lower_bound(main_chain.begin(), main_chain.end(), large[index]);
        typename T::iterator pos;
        pos = std::lower_bound(main_chain.begin(), bound, small[index]);
        main_chain.insert(pos, small[index]);
    }
    if (odd != -1)
    {
        typename T::iterator pos;
        pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd);
        main_chain.insert(pos, odd);
    }
    return main_chain;
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

const std::vector<int> &PmergeMe::getVector()
{
    return _vector;
}

const std::deque<int> &PmergeMe::getDeque()
{
    return _deque;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input)
{
    return mergeInsertSort(input);
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input)
{
    return mergeInsertSort(input);
}

PmergeMe::PmergeMe(char **av)
{
    if (!processInput(av))
        throw std::runtime_error("Error");
}

/**--------------Orthodox----------------*/

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