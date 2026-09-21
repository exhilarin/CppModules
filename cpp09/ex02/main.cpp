#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmergeme(av);
        std::cout << "Before : ";
        const std::vector<int> &input = pmergeme.getVector();
        for (size_t i = 0; i < input.size(); i++)
            std::cout << input[i] << " ";
        std::cout << std::endl;

        clock_t start = clock();
        std::vector<int> sortedVector = pmergeme.sortVector(input);
        clock_t end = clock();

        std::cout << "After : ";
        for (size_t i = 0; i < sortedVector.size(); i++)
            std::cout << sortedVector[i] << " ";
        std::cout << std::endl;

        double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of "
                  << sortedVector.size()
                  << " elements with std::vector : "
                  << vectorTime
                  << " us"
                  << std::endl;

        const std::deque<int> &dequeInput = pmergeme.getDeque();

        start = clock();
        std::deque<int> sortedDeque = pmergeme.sortDeque(dequeInput);
        end = clock();

        double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of "
                  << sortedDeque.size()
                  << " elements with std::deque : "
                  << dequeTime
                  << " us"
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    return 0;
}