
#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &otherClass);
        Bureaucrat &operator=(const Bureaucrat &otherClass);
        ~Bureaucrat();

        std::string         getName() const;
        int                 getGrade() const;
        
        void                increaseGrade();
        void                decreaseGrade();
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif
