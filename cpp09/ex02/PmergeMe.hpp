#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <utility>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
    
        int processInput(char **av);
    
    public:
        PmergeMe(char **av);
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
    
        const std::vector<int> &getVector();
        const std::deque<int> &getDeque();
    
        std::vector<int> sortVector(const std::vector<int> &input);
        std::deque<int> sortDeque(const std::deque<int> &input);
};

#endif