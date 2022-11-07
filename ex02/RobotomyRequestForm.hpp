//RobotomyRequestForm.hpp	CPP05   ex02

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {

	public:

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );	//Canonique	
		~RobotomyRequestForm( void );				//Canonique	

		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );//Canonique

		std::string getTarget( void ) const;
		std::string getAsciiTree( void ) const;

		bool	execute( const Bureaucrat & executor ) const;
		
	private:

		const std::string _target;

		RobotomyRequestForm( void );
};

std::ostream &		operator<<( std::ostream & o, RobotomyRequestForm const & i );


#endif
