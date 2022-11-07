//main.cpp	CPP05	ex02

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	
	Bureaucrat bur("Bob", 149);
/*
	std::cout << bur << std::endl;
	bur.increGrade();
	std::cout << bur.getGrade() << std::endl;
	std::cout << bur << std::endl;
	bur.decreGrade();
	std::cout << bur.getGrade() << std::endl;
	bur.decreGrade();
*/
	Bureaucrat bur1("Tom", 1);
	Bureaucrat bur2("Robert", 50);
	Bureaucrat bur3("Max", 70);
/*	ShrubberyCreationForm obj("Plantation", "jardin");
//	Form service("Service", 151, 140);
//	std::cout << obj.getName() << " - " << obj.getSignGrade() << std::endl;
	ShrubberyCreationForm toc("relocation", "terrasse");
	bur1.executeForm(toc);
	bur1.signForm(toc);
	bur2.signForm(toc);
	bur.executeForm(toc);


	Form com("commande", 50, 30);
//	Form nett("Nettoyage", 150, 51);
	bur.signForm(obj);
	std::cout << obj  << std::endl;
	bur1.signForm(obj);
	bur2.signForm(obj);
	bur1.executeForm(obj);
	bur.signForm(nett);
	bur2.signForm(nett);
	RobotomyRequestForm roto("roto", "Pendulard");
	bur.signForm(roto);
	bur3.signForm(roto);
	bur.executeForm(roto);
	bur2.executeForm(roto);
	bur1.executeForm(roto);

*/
	PresidentialPardonForm pard("pard", "Veinard");
	std::cout << pard << std::endl;
	bur.signForm(pard);
	bur3.signForm(pard);
	bur.executeForm(pard);
	bur2.executeForm(pard);
	bur1.signForm(pard);
	bur1.executeForm(pard);
	return 0;
}

