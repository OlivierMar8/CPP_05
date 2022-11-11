//Intern.cpp    CPP05    ex03

#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {

	std::cout << "Intern Default Constructor called" << std::endl;
	return;
}

Intern::Intern( Intern const & src ) {

	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Intern::~Intern( void ) {

		std::cout << "Intern Destructor called" << std::endl;
		return;
}

Intern &  Intern::operator=( Intern const & rhs) {

		(void)rhs;
        std::cout << "Intern assignement operator called" << std::endl;

        return *this;
}

Form*	Intern::makeForm(std::string name, std::string target ) {

	int i;
	Form* fo = NULL;
	std::string form_list[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	for (i = 0; i < 3; i++)
	{
		if (name == form_list[i])
			break;
	}
	if ( i == 3 )
	{
		std::cout << "Intern did'nt find this type of form: "
		   << name	<< std::endl;
		return fo;
	}
	try
	{
		switch (i)
		{
			case 0 :	fo = new ShrubberyCreationForm(target);
						break;
			case 1 : 	fo = new RobotomyRequestForm(target);
						break;
			case 2 :	fo = new PresidentialPardonForm(target);
		}	
	}
	catch ( std::bad_alloc & ba ) {
		std::cerr << "Allocation new form failed !" << std::endl;
	}
	std::cout << "Intern creates " << name << std::endl;	
	return fo;
}
