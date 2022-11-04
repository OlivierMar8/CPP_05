//ShrubberyCreationForm.hpp	CPP05   ex02

#ifndef SURUBBERYCREATIONFORM_HPP
# define SURUBBERYCREATIONFORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {

	public:

		ShrubberyCreationForm( std::string name );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );	//Canonique	
		virtual~ShrubberyCreationForm( void );				//Canonique	

		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );//Canonique

  /*      class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
	    };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
	    };

		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		int				getSignGrade( void ) const;
		int				getExecGrade( void ) const;

		bool			beSigned( const Bureaucrat & b );
*/		bool	execute( const Bureaucrat & executor ) const = 0;

	/*protected:

		const std::string 		_name;
		bool					_signed;
		const int				_signGrade;
		const int				_execGrade;
*/
};
/*
std::ostream &		operator<<( std::ostream & o, ShrubberyCreationForm const & i );
*/
#endif
