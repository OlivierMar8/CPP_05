//Form.cpp    CPP05    ex01

#include <iostream>
#include "Form.hpp"

Form::Form( void ) {

	std::cout << "Form Default Constructor called" << std::endl;
	return;
}

Form::Form( int const n ) : _(name n ), _signed(false), _signGrad(sg), _execGrad(eg) {

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

		std::cout << "Assignement mperator called" << std::endl;


		if ( this != &rhs )
			this->_foo = rhs.getFoo();
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

std::string	Form::getsSignGrade( void ) const {

		return _signGrade;
}

std::string	Form::getExecGrade( void ) const {

		return _execGrad;
}

std::ostream &	operator<<( std::ostream & o, Form const & i) {

	o << "Form name: " << i.getName() << "\n"
		<< "Signed: " << i.getSigned() << "\n" 
		<< "Grade to sign: " << i.getSignGrade<< "\n"
		<< "Grade to execute: " << i.getExecGrade()  << "\n"
	return o;
}
