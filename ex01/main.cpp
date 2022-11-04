//main.cpp	CPP05	ex01

#include <iostream>
#include "Bureaucrat.hpp"


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
	Bureaucrat bur4(bur);
	std::cout << bur4 << std::endl;

	Form obj("Objet", 50, 0);
	Form service("Service", 151, 140);
//	std::cout << obj.getName() << " - " << obj.getSignGrade() << std::endl;


	Form com("commande", 50, 30);
	Form nett("Nettoyage", 150, 51);
	bur.signForm(com);
	std::cout << com  << std::endl;
	bur1.signForm(com);
	bur2.signForm(com);

	bur.signForm(nett);
	bur2.signForm(nett);

	Form my_copy(com);
	std::cout << my_copy << std::endl;
	return 0;
}

