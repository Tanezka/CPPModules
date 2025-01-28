NAME      := doom
CC        := c++
FLAGS     := -Wall -Wextra -Werror -std=c++98
SRCS      := HumanA.cpp	HumanB.cpp Weapon.cpp main.cpp \

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
