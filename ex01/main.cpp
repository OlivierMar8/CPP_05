//main.cpp	CPP05	ex01

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	
	Bureaucrat bur("Bob", 149);

	Bureaucrat bur1("Tom", 1);
	Bureaucrat bur2("Robert", 50);
	Bureaucrat bur4(bur);
	std::cout << bur4 << std::endl;

	Form obj("Objet", 50, 0);
	Form service("Service", 151, 140);

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

/*
//Main.cpp ex01 Test Form
int	main( void ) {
    Form bur("Bob", 149, 40);

    std::cout << bur << std::endl;

    Form bur1("Tom", 0, 100);
    Form bur2("Robert", 1510, 10);
    Form bur3("Bruce", 1, 4);
    std::cout << bur3.getName() << " / " << bur3.getSigned() << std::endl;
    std::cout << bur3.getSignGrade() << " / " << bur3.getExecGrade() << std::endl;
    std::cout << bur3 << std::endl;

    Form bur4(bur3);
    std::cout << bur4 << std::endl;
    bur4 = bur;
    std::cout << bur4 << std::endl;
}
*/
/*
//Main ex00  Test Bureaucrat

#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{

    Bureaucrat bur("Bob", 149);

    std::cout << bur << std::endl;
    bur.increGrade();
    std::cout << bur << std::endl;
    bur.decreGrade();
    std::cout << bur << std::endl;
    bur.decreGrade();
    std::cout << bur.getGrade() << std::endl;
    std::cout << bur << std::endl;
    bur.decreGrade();
    std::cout << bur.getGrade() << std::endl;
    bur.decreGrade();

    Bureaucrat bur1("Tom", 0);
    Bureaucrat bur2("Robert", 1510);
    Bureaucrat bur3("Bruce", 1);
    std::cout << bur3.getName() << " / " << bur3.getGrade() << std::endl;
    bur3.increGrade();
    std::cout << bur3 << std::endl;

    Bureaucrat bur4(bur3);
    std::cout << bur4 << std::endl;
    bur4 = bur;
    std::cout << bur4 << std::endl;

    return 0;
} 
*/


