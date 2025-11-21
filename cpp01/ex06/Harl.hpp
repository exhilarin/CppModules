
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

enum level {DEBUG, INFO, WARNING, ERROR};

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        void complain(char *av[]);
};

#endif