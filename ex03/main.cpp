//main.cpp	CPP05	ex03

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
/*
int	main( void )
{
	
	Bureaucrat bur("Bob", 149);
	Bureaucrat bur1("Tom", 1);
	Intern bos;
	Intern cos(bos);
	Intern pos;

	pos = bos;

	Form* rrf;
	rrf = bos.makeForm("aa", "Bender");
	if (rrf)
	{
		bur1.signForm(*rrf);
		bur1.executeForm(*rrf);
	}
	delete rrf;
	rrf = pos.makeForm("shrubbery creation", "Dona");
	if (rrf)
	{
		bur1.signForm(*rrf);
		bur1.executeForm(*rrf);
	}
	delete rrf;

	rrf = cos.makeForm("robotomy request", "Donald");
	if (rrf)
	{
		bur1.signForm(*rrf);
		bur1.executeForm(*rrf);
	}
	delete rrf;

	rrf = bos.makeForm("presidential pardon", "Barack");
	if (rrf)
	{
		bur.signForm(*rrf);
		bur1.signForm(*rrf);
		bur1.executeForm(*rrf);
	}
	delete rrf;
	return 0;
}
*/
/*
// test ex02 projet
int	main( void )
{
	
	Bureaucrat bur("Bob", 149);


	Bureaucrat bur1("Tom", 1);
	Bureaucrat bur2("Robert", 50);
	Bureaucrat bur3("Max", 70);

	ShrubberyCreationForm obj("jardin");
	std::cout << obj.getName() << " - " << obj.getSignGrade() << std::endl;
	ShrubberyCreationForm toc("terrasse");
	bur1.executeForm(toc);
	bur1.signForm(toc);
	bur2.signForm(toc);
	bur.executeForm(toc);
	bur.signForm(obj);
	std::cout << obj  << std::endl;
	bur1.signForm(obj);
	bur2.signForm(obj);
	bur1.executeForm(obj);
	RobotomyRequestForm roto("Pendulard");
	bur.signForm(roto);
	bur3.signForm(roto);
	bur.executeForm(roto);
	std::cout << roto << std::endl;
	bur2.executeForm(roto);
	bur1.executeForm(roto);

	RobotomyRequestForm roto1("Pendulard");
	bur3.signForm(roto1);
	RobotomyRequestForm roto2("Pendulard");
	bur3.signForm(roto2);
	RobotomyRequestForm roto3("Pendulard");
	bur3.signForm(roto3);
	bur1.executeForm(roto1);
	bur1.executeForm(roto2);
	bur1.executeForm(roto3);
	bur1.executeForm(roto3);
	bur1.executeForm(roto3);
	bur1.executeForm(roto3);

	PresidentialPardonForm pard("Veinard");
	std::cout << pard << std::endl;
	bur.signForm(pard);
	bur3.signForm(pard);
	bur.executeForm(pard);
	bur2.executeForm(pard);
	bur1.signForm(pard);
	bur1.executeForm(pard);
	return 0;
}
*/
/*
// Test ShrubberyForm
int main( void ) {
//	ShrubberyCreationForm a;
	ShrubberyCreationForm toc("terrasse");
	ShrubberyCreationForm ter("parking");
	std::cout << toc << std::endl;
	std::cout << ter << std::endl;
	ShrubberyCreationForm ab(toc);
	std::cout << ab << std::endl;
	ab = ter;
	std::cout << ab << std::endl;
	return 0;
}
*/	


// Test Presidential
int main( void ) {
//	PresidentialPardonForm a;
	PresidentialPardonForm toc("terrasse");
	PresidentialPardonForm ter("parking");
	std::cout << toc << std::endl;
	std::cout << ter << std::endl;
	PresidentialPardonForm ab(toc);
	std::cout << ab << std::endl;
	ab = ter;
	std::cout << ab << std::endl;
	return 0;
}

/*	
// Test Robotomy
int main( void ) {
//	RobotomyRequestForm a;
	RobotomyRequestForm toc("terrasse");
	RobotomyRequestForm ter("parking");
	std::cout << toc << std::endl;
	std::cout << ter << std::endl;
	RobotomyRequestForm ab(toc);
	std::cout << ab << std::endl;
	ab = ter;
	std::cout << ab << std::endl;
	return 0;
}
*/	
/*
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
*/
/*
//Main.cpp ex01 Test Form
int	main( void ) {
    Form bur("Bob", 149, 40);

    std::cout << bur << std::endl;
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


