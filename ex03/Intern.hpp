//Intern.hpp CPP05   ex03

#ifndef INTERN_HPP
# define INTERN_HPP

# include <ostream>
# include <string>
# include "Form.hpp"

class Intern {

	public:

		Intern( void );					//Canonique
		Intern( Intern const & src );	//Canonique	
		~Intern( void );				//Canonique	

		Intern &	operator=( Intern const & rhs );//Canonique

		Form*		makeForm( std::string name, std::string target );
};

#endif
