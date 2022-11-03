//Form.hpp CPP05   ex01

#ifndef FORM_HPP
# define FORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:

		Form( void );					//Canonique
		Form( std::string name, int sg, int eg );
		Form( Form const & src );	//Canonique	
		~Form( void );				//Canonique	

		Form &	operator=( Form const & rhs );//Canonique

        class GradeTooHighException : public std::exception {
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

		void			beSigned( const Bureaucrat & b );

	private:

		const std::string 		_name;
		bool					_signed;
		const int				_signGrade;
		const int				_execGrade;

};

std::ostream &		operator<<( std::ostream & o, Form const & i );

#endif
