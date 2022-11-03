//Form.cpp    CPP05    ex01

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name( "" ), _signed(false), _signGrade(1), _execGrade(Bureaucrat::maxGrade) {

	std::cout << "Form Default Constructor called" << std::endl;
	return;
}

Form::Form( std::string n, int sg, int eg ) : _name( n ), _signed(false), _signGrade(sg), _execGrade(eg) {

	std::cout << "Form Parametric Constructor called" << std::endl;
	return;
}

Form::Form( Form const & src ) : _name( src.getName()), _signed( src.getSigned()), _signGrade( src.getSignGrade()), _execGrade( src.getExecGrade()) {

	std::cout << "Form Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Form::~Form( void ) {

		std::cout << "Form Destructor called" << std::endl;
		return;
}

Form &  Form::operator=( Form const & rhs) {

        std::cout << "Assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
            std::cout << "Only the isSigned has been copied. Others attributes are const !" << std::endl;
        }
        return *this;
}

const char* Form::GradeTooHighException::what () const throw() {
    return (" his grade is too high !");
}

const char* Form::GradeTooLowException::what () const throw() {
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

		return _execGrade;
}

void	Form::beSigned( const Bureaucrat & b) {

	if (_signed == false)
	{
		if ( _signGrade < b.getGrade())
			throw Form::GradeTooLowException();
		else
			_signed = true;
	}
	else
		std::cout << "The form " << _name << " is alredy signed." << std::endl;
	return;
}	

std::ostream &	operator<<( std::ostream & o, Form const & i) {

	o << "Form name: " << i.getName() << "\n"
		<< "Signed: " << i.getSigned() << "\n" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n"
		<< "Grade to execute: " << i.getExecGrade()  << "\n";
	return o;
}
