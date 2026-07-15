
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
    private:
        std::stack<int> _stack;
        bool Operation(char operation);

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string &expression);
};

#endif