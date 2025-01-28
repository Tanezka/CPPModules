NAME      := small_fight
CC        := c++
FLAGS     := -Wall -Wextra -Werror -std=c++98
SRCS      := ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp\

OBJS      := $(SRCS:.cpp=.o)

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created ✔️"

all:		${NAME}

clean:
			@${RM} $(OBJS)
			@echo ".o files are gone ✔️"

fclean:		clean
			@rm -rf $(NAME)
			@echo "Executable is gone ✔️"

re:			fclean all

.PHONY:		all clean fclean re
