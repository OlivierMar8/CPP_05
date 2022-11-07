//ShrubberyCreationForm.hpp	CPP05   ex02

#ifndef SURUBBERYCREATIONFORM_HPP
# define SURUBBERYCREATIONFORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {

	public:

		ShrubberyCreationForm( std::string name, std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );	//Canonique	
		~ShrubberyCreationForm( void );				//Canonique	

		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );//Canonique

		std::string getTarget( void ) const;
		std::string getAsciiTree( void ) const;

		bool	execute( const Bureaucrat & executor ) const;
		
	private:

		const std::string _target;
		static const std::string _asciiTree;

		ShrubberyCreationForm( void );
};

std::ostream &		operator<<( std::ostream & o, ShrubberyCreationForm const & i );


#endif
