
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define MAX_INT 2147483647

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

        int processInput(char **av);

    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortVector();
        void sortDeque();
};

#endif