//Bureaucrat.cpp    CPP05    ex01

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

	std::cout << "Default Constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {

	std::cout << "Parametric Constructor called" << std::endl;

	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
		else {
			_grade = grade;
		}
	}

	catch (std::exception& e) {

		std::cerr << e.what() << std::endl;
	return;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {

	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs) {

const		std::cout << "Assignement operator called" << std::endl;

		if ( this != &rhs ) {
			*this = rhs;
		}

		return *this;
}

const char*	Bureaucrat::GradeTooHighException::what () const throw() {
	return ("Bureaucrat: the grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw() {
	return ("Bureaucrat: the grade is too low !");
}

std::string		Bureaucrat::getName( void) const {

	return _name;
}

int		Bureaucrat::getGrade( void) const {

	return _grade;
}

void	Bureaucrat::increGrade( void ) {

	try {
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		else 
			_grade--;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		}
	return;
}

void	Bureaucrat::decreGrade( void ) {

	try {
		if (_grade >= 150)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade++;
	}

	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		}

	return;
}

void	signForm( Form& fo) {
	try
	{
		fo.beSigned(&this);
		std::cout << _name << " signed " << fo.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
/*
	if (! fo.getSigned)
		if (fo.getSignGrad <= _grade) {

		}
		else

	else
	{
		std::cout << "Form " << fo.getName() << " already signed !"
			<< std:endl;
}
*/
std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i) {

	o << i.getName() <<" , bureaucrat grade " << i.getGrade();

	return o;
}
