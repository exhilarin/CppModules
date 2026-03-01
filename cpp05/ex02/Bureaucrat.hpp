
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class AForm;
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &otherClass);
        Bureaucrat &operator=(const Bureaucrat &otherClass);
        ~Bureaucrat();

        std::string         getName() const;
        int                 getGrade() const;
        
        void                increaseGrade();
        void                decreaseGrade();
        void                signForm(AForm &Aform);

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
