//RobotomyRequestForm.cpp    CPP05    ex02

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyDefault", 72, 45), _target( "" ) {

	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string n, std::string target ) : Form(n, 72, 45),  _target( target ) {

	std::cout << "RobotomyRequestForm Parametric Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form(src.getName(), src.getSignGrade(), src.getExecGrade()), _target( src.getTarget()) {

	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

		std::cout << "RobotomyRequestForm Destructor called" << std::endl;
		return;
}

// _name, grade assignement is not possible because const !
RobotomyRequestForm &  RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs) {

        std::cout << "RobotomyRequestForm assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
        }
        return *this;
}

std::string RobotomyRequestForm::getTarget( void ) const {

        return _target;
}

bool	RobotomyRequestForm::execute( const Bureaucrat & executor) const {

		if (_signed == true)
		{
			if ( _signGrade < executor.getGrade())
	            throw Form::GradeTooLowException();
			std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
			return true;
		}
		else
			throw Form::FormNotSignedException();
}

std::ostream &	operator<<( std::ostream & o, RobotomyRequestForm const & i) {

	o << "RobotomyRequestForm name: " << i.getName() << "\n\t"
		<< "Signed: " << (i.getSigned() ? "true" : "false") << "\n\t" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n\t"
		<< "Grade to execute: " << i.getExecGrade()  << "\n\t"
		<< "Target: " << i.getTarget() << "\n";
	return o;
}
