//Bureaucrat.hpp CPP05   ex00

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <string>

class Bureaucrat {

	public:

		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );	//Canonique	
		~Bureaucrat( void );				//Canonique	

		Bureaucrat &	operator=( Bureaucrat const & rhs );//Canonique

		class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

		class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void		increGrade( void );
		void		decreGrade( void );

		static const int	maxGrade = 1;
		static const int	minGrade = 150;

	private:

		Bureaucrat( void );					//Canonique
		const std::string	_name;
		int					_grade;

};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i );

#endif
