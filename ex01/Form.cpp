//Form.cpp    CPP05    ex01

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name( "" ), _signed(false), _signGrade(1), _execGrade(1) {

	std::cout << "Form Default Constructor called" << std::endl;
/*	_name = "";
	_signed = false;
	_signGrade = Bureaucrat::minGrade;
	_execGrade = Bureaucrat::minGrade;
*/	return;
}

Form::Form( std::string n, int sg, int eg ) : _name( n ), _signed(false), _signGrade(sg), _execGrade(eg) {

	std::cout << "Form Parametric Constructor called" << std::endl;
	return;
}

Form::Form( Form const & src ) {

	std::cout << "Form Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Form::~Form( void ) {

		std::cout << "Form Destructor called" << std::endl;
		return;
}

Form &	Form::operator=( Form const & rhs) {

		std::cout << "Assignement operator called" << std::endl;

		if ( this != &rhs ) {
			_name = rhs.getName();
			_signed = rhs.getSigned();
			_signGrade = getSignGrade();
			_execGrade = getExecGrade();
		}
		return *this;
}

const char* Form::GradeTooHighException::what () const throw() {
    return (" his grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what () const throw() {
    return (" his grade is too low !");
}

std::string	Form::getName( void ) const {

		return _name;
}

bool	Form::getSigned( void ) const {

		return _signed;
}

int		Form::getSignGrade( void ) const {

		return _signGrade;
}

int		Form::getExecGrade( void ) const {

		return _execGrad;
}

std::ostream &	operator<<( std::ostream & o, Form const & i) {

	o << "Form name: " << i.getName() << "\n"
		<< "Signed: " << i.getSigned() << "\n" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n"
		<< "Grade to execute: " << i.getExecGrade()  << "\n";
	return o;
}
