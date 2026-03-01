
#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;
# include <iostream>
# include <exception>

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

    protected:
        void       checkExecution(const Bureaucrat &executor) const;

    public:
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &otherClass);
        AForm &operator=(const AForm &otherClass);
        virtual ~AForm();

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void        beSigned(const Bureaucrat &b);

        virtual void execute(const Bureaucrat &executor) const = 0;

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

        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif