
#include "Bureaucrat.hpp"

const char* GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &otherClass) : name(otherClass.name), grade(otherClass.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &otherClass)
{
    if (this != &otherClass)
        this->grade = otherClass.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increaseGrade()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
