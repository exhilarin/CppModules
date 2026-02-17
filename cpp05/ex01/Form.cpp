
#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low.";
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "Form is already signed.";
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &otherClass)
    : name(otherClass.name), isSigned(otherClass.isSigned),
        gradeToSign(otherClass.gradeToSign), gradeToExecute(otherClass.gradeToExecute) {}

Form &Form::operator=(const Form &otherClass)
{
    if (this != &otherClass)
        this->isSigned = otherClass.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (this->isSigned)
        throw AlreadySignedException();
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName()
       << ", sign grade " << f.getGradeToSign()
       << ", execute grade " << f.getGradeToExecute()
       << ", signed: " << (f.getIsSigned() ? "true" : "false");
    return os;
}
