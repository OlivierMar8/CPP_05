//main.cpp	CPP04	ex00

#include <iostream>
#include "Bureaucrat.hpp"


int	main( void )
{
	
	Bureaucrat bur("Bob", 120);

	std::cout << bur << std::endl;
	bur.increGrade();
	std::cout << bur.getGrade() << std::endl;
	std::cout << bur << std::endl;
	bur.decreGrade();
	std::cout << bur.getGrade() << std::endl;


	Bureaucrat bur1("Robert", 1510);

	return 0;
}

