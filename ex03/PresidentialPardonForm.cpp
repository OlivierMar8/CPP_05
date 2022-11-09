//PresidentialPardonForm.cpp    CPP05    ex03

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("Presidential", 25, 5), _target( "" ) {

	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("Presidential", 25, 5),  _target( target ) {

	std::cout << "PresidentialPardonForm Parametric Constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form("Presidential", src.getSignGrade(), src.getExecGrade()), _target( src.getTarget()) {

	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

		std::cout << "PresidentialPardonForm Destructor called" << std::endl;
		return;
}

// _name, grade assignement is not possible because const !
PresidentialPardonForm &  PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs) {

        std::cout << "PresidentialPardonForm assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
        }
        return *this;
}

std::string PresidentialPardonForm::getTarget( void ) const {

        return _target;
}

bool	PresidentialPardonForm::execute( const Bureaucrat & executor) const {

		if (_signed == true)
		{
			if ( _signGrade < executor.getGrade())
	            throw Form::GradeTooLowException();
			std::cout << _target << " was forgiven by Zaphod Beeblebrox" << std::endl;
			return true;
		}
		else
			throw Form::FormNotSignedException();
}

std::ostream &	operator<<( std::ostream & o, PresidentialPardonForm const & i) {

	o << "PresidentialPardonForm name: " << i.getName() << "\n\t"
		<< "Signed: " << (i.getSigned() ? "true" : "false") << "\n\t" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n\t"
		<< "Grade to execute: " << i.getExecGrade()  << "\n\t"
		<< "Target: " << i.getTarget() << "\n";
	return o;
}
