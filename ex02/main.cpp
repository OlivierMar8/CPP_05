//main.cpp	CPP05	ex02

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	
	Bureaucrat bur("Bob", 149);

	std::cout << bur << std::endl;
	bur.increGrade();
	std::cout << bur.getGrade() << std::endl;
	std::cout << bur << std::endl;
	bur.decreGrade();
	std::cout << bur.getGrade() << std::endl;
	bur.decreGrade();

	Bureaucrat bur1("Tom", 1);
	Bureaucrat bur2("Robert", 50);
	ShrubberyCreationForm obj("Plantation", "jardin");
//	Form service("Service", 151, 140);
//	std::cout << obj.getName() << " - " << obj.getSignGrade() << std::endl;


//	Form com("commande", 50, 30);
//	Form nett("Nettoyage", 150, 51);
	bur.signForm(obj);
	std::cout << obj  << std::endl;
	bur1.signForm(obj);
	bur2.signForm(obj);
/*
	bur.signForm(nett);
	bur2.signForm(nett);
*/
	return 0;
}

