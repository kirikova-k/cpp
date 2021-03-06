#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string const &_name, int rank) : name(_name)
{
	if (rank < 1)
		throw GradeTooHighException();
	else if (rank > 150)
		throw GradeTooLowException();
	else
		grade = rank;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance) : name(instance.getName())
{
	if (instance.getGrade() < 1)
		throw GradeTooHighException();
	else if (instance.getGrade() > 150)
		throw GradeTooLowException();
	else
		grade = instance.getGrade();
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->grade = rhs.getGrade();
	return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incGrade(void)
{
	if (this->grade -1 < 1)
		throw GradeTooHighException();
	else
		this->grade--;
	return ;
}

void Bureaucrat::decGrade(void)
{
	if (this->grade +1 > 150)
		throw GradeTooLowException();
	else
		this->grade++;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream&operator<<(std::ostream &ostream, Bureaucrat const &instance)
{
	ostream << instance.getName() << " bureaucrat grade: " << instance.getGrade() << std::endl;
	return (ostream);
}

