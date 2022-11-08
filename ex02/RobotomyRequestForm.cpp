//RobotomyRequestForm.cpp    CPP05    ex02

#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("Robotomy", 72, 45), _target( "" ) {

	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("Robotomy", 72, 45),  _target( target ) {

	std::cout << "RobotomyRequestForm Parametric Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form("Robotomy", src.getSignGrade(), src.getExecGrade()), _target( src.getTarget()) {

	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

		std::cout << "RobotomyRequestForm Destructor called" << std::endl;
		return;
}

// _name, grade, target assignement is not possible because const !
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
			if (std::rand() % 100 > 50)
			{
				std::cout << _target << " has been robotomized !" << std::endl;
				return true;
			}
			else
			{
				std::cout << "Robotomization was unsuccessful !" << std::endl;
				return false;
			}
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
