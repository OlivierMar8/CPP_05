//PresidentialPardonForm.hpp	CPP05   ex03

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {

	public:

		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );	//Canonique	
		~PresidentialPardonForm( void );				//Canonique	

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );//Canonique

		std::string getTarget( void ) const;

		bool	execute( const Bureaucrat & executor ) const;
		
	private:

		const std::string _target;

		PresidentialPardonForm( void );
};

std::ostream &		operator<<( std::ostream & o, PresidentialPardonForm const & i );


#endif
