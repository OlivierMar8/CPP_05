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
	switch (i)
	{
		case 0 :	fo = new ShrubberyCreationForm(target);
					break;
		case 1 : 	fo = new RobotomyRequestForm(target);
					break;
		case 2 :	fo = new PresidentialPardonForm(target);
	}	
	if (i >= 0 && i <= 2)
		std::cout << "Intern creates " << name << std::endl;	
	else
		std::cout << "Intern did'nt find this type of form !" << std::endl;

	return fo;
}
