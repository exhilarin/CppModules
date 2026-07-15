
#include "RPN.hpp"

bool RPN::Operation(char operation)
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }

    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    int result;

    if (operation == '+')
        result = left + right;
    else if (operation == '-')
        result = left - right;
    else if (operation == '*')
        result = left * right;
    else
    {
        if (right == 0)
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        result = left / right;
    }
    _stack.push(result);
    return true;
}

void RPN::calculate(const std::string &expression)
{
    char token;
    for (size_t i = 0; i < expression.length(); i++)
    {
        token = expression[i];
        if (token == ' ')
            continue;
        if (isdigit(token))
        {
            _stack.push(token - '0');
        }
        else if (token == '+' || token == '-' ||
                 token == '*' || token == '/')
        {
            if(!Operation(token))
                return ;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << _stack.top() << std::endl;
}

/*--------------Orthodox----------------*/
RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}