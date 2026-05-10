
#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
# include <vector>

class Span
{
    private:
        Span();
        unsigned int _maxCap;
        std::vector<int> _numbers;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);

        int shortestSpan() const;
        int longestSpan() const;
};

#endif