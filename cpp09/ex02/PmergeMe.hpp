
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define MAX_INT 2147483647

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        PmergeMe(char **av);
        int processInput(char **av);

        // void sortVector();
        // void sortDeque();
};

#endif