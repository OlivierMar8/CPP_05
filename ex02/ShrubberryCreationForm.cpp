//ShrubberyCreationForm.cpp    CPP05    ex02

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : _name( "" ), _signed(false), _signGrade(145), _execGrade(137) {

	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string n ) : _name( n ), _signed(false), _signGrade(145), _execGrade(137) {

	std::cout << "ShrubberyCreationForm Parametric Constructor called" << std::endl;
/*
	 try {
        if (sg < Bureaucrat::maxGrade || eg < Bureaucrat::maxGrade)
            throw ShrubberyCreationForm::GradeTooHighException();
		else if (sg > Bureaucrat::maxGrade || eg > Bureaucrat::maxGrade)
            throw ShrubberyCreationForm::GradeTooLowException();
    }
    catch (std::exception& e) {

        std::cerr << "The form " << e.what() << std::endl;
    }
*/	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : _name( src.getName()), _signed( src.getSigned()), _signGrade( src.getSignGrade()), _execGrade( src.getExecGrade()) {

	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

		std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
		return;
}

ShrubberyCreationForm &  ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs) {

        std::cout << "Assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
            std::cout << "Only the isSigned has been copied. Others attributes are const !" << std::endl;
        }
        return *this;
}

const char* ShrubberyCreationForm::GradeTooHighException::what () const throw() {
    return (" grade is too high !");
}

const char* ShrubberyCreationForm::GradeTooLowException::what () const throw() {
    return (" grade is too low !");
}

std::string	ShrubberyCreationForm::getName( void ) const {

		return _name;
}

bool	ShrubberyCreationForm::getSigned( void ) const {

		return _signed;
}

int		ShrubberyCreationForm::getSignGrade( void ) const {

		return _signGrade;
}

int		ShrubberyCreationForm::getExecGrade( void ) const {

		return _execGrade;
}

bool	ShrubberyCreationForm::beSigned( const Bureaucrat & b) {

	if (_signed == false)
	{
		if ( _signGrade < b.getGrade())
			throw ShrubberyCreationForm::GradeTooLowException();
		else {
				_signed = true;
				return false;
			}
	}
	else {
			std::cout << "The form " << _name << " is alredy signed." << std::endl;
			return true;
	}
}	

std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & i) {

	o << "ShrubberyCreationForm name: " << i.getName() << "\n"
		<< "Signed: " << (i.getSigned() ? "true" : "false") << "\n" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n"
		<< "Grade to execute: " << i.getExecGrade()  << "\n";
	return o;
}
