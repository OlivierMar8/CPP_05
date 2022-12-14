//Bureaucrat.cpp    CPP05    ex02

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {

	std::cout << "Bureaucrat Parametric Constructor called" << std::endl;

	try {
		if (grade < maxGrade)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > minGrade)
			throw Bureaucrat::GradeTooLowException();
		else {
			_grade = grade;
		}
	}

	catch (std::exception& e) {

		std::cerr << e.what() << std::endl;
	}
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name( src.getName()), _grade(src.getGrade()) {

	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat( void ) {

	std::cout << "Bureaucrat Destructor called" << std::endl;
	return;
}

// _name assignement is not possible because it's const !
Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs) {

		std::cout << "Bureaucrat Assignement operator called" << std::endl;

		if ( this != &rhs ) {
			_grade = rhs.getGrade();
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
		if (_grade <= maxGrade)
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
		if (_grade >= minGrade)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}

	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		}

	return;
}

void	Bureaucrat::signForm( Form & fo ) {

	try
   	{
		if (! fo.beSigned( *this ))
			std::cout << _name << " signed " << fo.getName() << std::endl;
	}
	catch (std::exception & e)
   	{
		std::cout << _name << " could'nt sign " << fo.getName() << " because his" 
		<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( Form const & form ) {

	try
	{
		if ( form.execute(*this) )
			std::cout << _name << " executed " << form.getName() << std::endl;
		else
			std::cout << _name << " could'nt execute " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << _name << " could'nt execute " << form.getName() << " because his" 
		<< e.what() << std::endl;
	}
	catch (Form::FormNotSignedException & e)
	{
		std::cout << _name << " could'nt execute " << form.getName()
		   	<< " because the form is not signed !" << std::endl;
	}
}	

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i) {

	o << i.getName() <<", bureaucrat grade " << i.getGrade();

	return o;
}
