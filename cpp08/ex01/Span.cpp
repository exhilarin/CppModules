
#include "Span.hpp"

Span::Span() : _maxCap(0) {}
Span::Span(unsigned int N) : _maxCap(N) {}
Span::Span(const Span &other) : _maxCap(other._maxCap), _numbers(other._numbers) {}
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxCap = other._maxCap;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxCap)
        throw std::out_of_range("Span is full!"); 
    _numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers!");
    std::vector<int> temp = _numbers;
    std::sort(temp.begin(), temp.end());

    int min_diff = temp[1] - temp[0];
    for (size_t i = 1; i < temp.size(); i++)
    {
        int diff = temp[i] - temp[i - 1];
        if (min_diff > diff)
            min_diff = diff;
    }
    return min_diff;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers!");
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    return (max - min);
}