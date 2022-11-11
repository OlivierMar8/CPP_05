#Makefile   CPP05   ex02

SRCS		= main.cpp Bureaucrat.cpp Form.cpp \
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

OBJS		= $(SRCS:.cpp=.o)

NAME		= form02

CC			= c++ #c++-12

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra -std=c++98


all:		${NAME}

%.o: %.cpp
			$(CC) $(CFLAGS) -c $< 

${NAME}:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			

.PHONY:		all clean fclean  re

clean:	
			$(RM) $(OBJS)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all
