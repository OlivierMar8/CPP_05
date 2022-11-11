//ShrubberyCreationForm.cpp    CPP05    ex03

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const std::string ShrubberyCreationForm::_asciiTree =
"                          MM                              \n"
"                         MMMM                             \n"
"         ==             MMMMMM                  N         \n"
"        ====           MMMMMMMM                NNM        \n"
"       ======         MMMMMMMMMM              NNNNN       \n"
"     ==========      MMMMMMMMMMMM          NNNNNNNNNNN    \n"
"    ============      MMMMMMMMMM         NNNNNN W NNNNNN  \n"
"         ||            MMMMMMMM        NNNNNNNN W NNNNNNNN\n"
"         ||               ||                    W         \n"
"         ||              ||||                   W         \n"
"         ||             ||||||                  W         \n"
"==========================================================\n";



ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("Shrubbery", 145, 137), _target( "" ) {

	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("Shrubbery", 145, 137),  _target( target ) {

	std::cout << "ShrubberyCreationForm Parametric Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form("Shrubbery", src.getSignGrade(), src.getExecGrade()), _target( src.getTarget()) {

	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

		std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
		return;
}

// _name, grade assignement is not possible because const !
ShrubberyCreationForm &  ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs) {

        std::cout << "ShrubberryCreationForm assignement operator called" << std::endl;

        if ( this != &rhs ) {
            _signed = rhs.getSigned();
        }
        return *this;
}

std::string ShrubberyCreationForm::getTarget( void ) const {

        return _target;
}

std::string ShrubberyCreationForm::getAsciiTree( void ) const {

        return _asciiTree;
}

bool	ShrubberyCreationForm::execute( const Bureaucrat & executor) const {

		if (_signed == true)
		{
			if ( _signGrade < executor.getGrade())
	            throw Form::GradeTooLowException();
			std::ofstream	outFile;
			std::string		fileName = this->getTarget();

			fileName.append("_shrubbery");
			outFile.open(fileName.data());
			if (outFile.is_open()) {
				outFile << this->getAsciiTree() << std::endl;
				outFile.close();
				return true;
			}
			else {
				std::cerr << "Error opening file " << fileName << std::endl;	
				return false;
			}
		}
		else
			throw Form::FormNotSignedException();
}



std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & i) {

	o << "ShrubberyCreationForm name: " << i.getName() << "\n\t"
		<< "Signed: " << (i.getSigned() ? "true" : "false") << "\n\t" 
		<< "Grade to sign: " << i.getSignGrade()<< "\n\t"
		<< "Grade to execute: " << i.getExecGrade()  << "\n\t"
		<< "Target: " << i.getTarget() << "\n\t"
		<< "Ascii Tree:\n " << i.getAsciiTree() << "\n"; 
	return o;
}
