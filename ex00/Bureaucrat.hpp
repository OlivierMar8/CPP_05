//Bureaucrat.hpp CPP05   ex00

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <stdexcept>

class Bureaucrat {

	public:

		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );	//Canonique	
		~Bureaucrat( void );				//Canonique	

		Bureaucrat &	operator=( Bureaucrat const & rhs );//Canonique

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void		increGrade( void );
		void		decreGrade( void );


	private:

		Bureaucrat( void );					//Canonique
		const std::string	_name;
		int					_grade;

		class GradeTooHighException : public std::exception
	{
	};

		class GradeTooLowException : public std::exception
	{
	};

};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i );

#endif
