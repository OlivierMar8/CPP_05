//Form.hpp CPP05   ex01

#ifndef FORM_HPP
# define FORM_HPP

#include <ostream>
#include <string>

class Form {

	public:

		Form( int const n );
		Form( std::string name, int siGrad, int exeGrad );
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
		int				getSignGradie( void ) const;
		int				getExecGrade( void ) const;

		void			beSigned( Bureaucrat b );

	private:

		const std::string 		_name;
		bool					_signed;
		const int				_signGrad;
		const int				_execGrad;

		Form( void );					//Canonique
};

std::ostream &		operator<<( std::ostream & o, Form const & i );

#endif
