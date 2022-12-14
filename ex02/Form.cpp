//Form.cpp    CPP05    ex02

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name( "" ), _signed(false), _signGrade(Bureaucrat::maxGrade), _execGrade(Bureaucrat::maxGrade) {

	std::cout << "Form Default Constructor called" << std::endl;
	return;
}

Form::Form( std::string n, int sg, int eg ) : _name( n ), _signed(false), _signGrade(sg), _execGrade(eg) {

	std::cout << "Form Parametric Constructor called" << std::endl;

	 try {
        if (sg < Bureaucrat::maxGrade || eg < Bureaucrat::maxGrade)
            throw Form::GradeTooHighException();
		else if (sg > Bureaucrat::minGrade || eg > Bureaucrat::minGrade)
            throw Form::GradeTooLowException();
    }
    catch (std::exception& e) {

        std::cerr << "The form" << e.what() << std::endl;
    }
	return;
}

Form::Form( Form const & src ) : _name( src.getName()), _signed( src.getSigned()), _signGrade( src.getSignGrade()), _execGrade( src.getExecGrade()) {

	std::cout << "Form Copy Constructor called" << std::endl;
	return;
}

Form::~Form( void ) {

		std::cout << "Form Destructor called" << std::endl;
		return;
}

// _name, grade assignement is not possible because const !
Form &  Form::operator=( Form const & rhs) {

        std::cout << "Form assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
        }
        return *this;
}

const char* Form::GradeTooHighException::what () const throw() {
    return (" grade is too high !");
}

const char* Form::GradeTooLowException::what () const throw() {
    return (" grade is too low !");
}

const char* Form::FormNotSignedException::what () const throw() {
    return (" is not signed !");
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

		return _execGrade;
}

bool	Form::beSigned( const Bureaucrat & b) {

	if (_signed == false)
	{
		if ( _signGrade < b.getGrade())
			throw Form::GradeTooLowException();
		else {
				_signed = true;
				return false;
			}
	}
	else {
			std::cout << "The form " << _name << " is already signed." << std::endl;
			return true;
	}
}	

std::ostream &	operator<<( std::ostream & o, Form const & i) {

	o << "Form name: " << i.getName() << "\n\t"
		<< "Signed: " << (i.getSigned() ? "true" : "false") << "\n\t" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n\t"
		<< "Grade to execute: " << i.getExecGrade();
	return o;
}
