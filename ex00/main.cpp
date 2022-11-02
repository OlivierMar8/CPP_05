//main.cpp	CPP04	ex00

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

	Bureaucrat bur1("Tom", 0);
	Bureaucrat bur2("Robert", 1510);

	return 0;
}

