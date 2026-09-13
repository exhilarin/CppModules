
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        
        int  processInput(char **av);
        void PmergeMe::makePairs(std::vector<std::pair<int, int>> &pairs);

        void sortVector();
        void sortDeque();

    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
};

#endif