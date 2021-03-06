#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

Bureaucrat::Bureaucrat(Bureaucrat const &initstate) : name(initstate.getName())
{
	if (initstate.getGrade() < 1)
		throw GradeTooHighException();
	else if (initstate.getGrade() > 150)
		throw GradeTooLowException();
	else
		grade = initstate.getGrade();
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

void Bureaucrat::signForm(Form &form) const
{
	if (this->getGrade() > form.getRGradeSign())
	{
		std::cout << "Bureaucrat " << this->name;
		std::cout << " couldn’t sign form " << form.getName();
		std::cout << " because his grade is too low." << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << this->name;
		std::cout << " signed form " << form.getName() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[1;36mException: \033[0;37mGrade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[1;36mException: \033[0;37mGrade is too low!");
}

std::ostream&operator<<(std::ostream &ostream, Bureaucrat const &initstate)
{
	ostream << initstate.getName() << " bureaucrat grade: " << initstate.getGrade() << std::endl;
	return (ostream);
}

