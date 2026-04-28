
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low.";
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "AForm is already signed.";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed.";
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &otherClass)
    : name(otherClass.name), isSigned(otherClass.isSigned),
        gradeToSign(otherClass.gradeToSign), gradeToExecute(otherClass.gradeToExecute) {}

AForm &AForm::operator=(const AForm &otherClass)
{
    if (this != &otherClass)
        this->isSigned = otherClass.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (this->isSigned)
        throw AlreadySignedException();
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
    if (!this->isSigned)
        throw NotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName()
       << ", sign grade " << f.getGradeToSign()
       << ", execute grade " << f.getGradeToExecute()
       << ", signed: " << (f.getIsSigned() ? "true" : "false");
    return os;
}
