NAME      := zombie
CC        := c++
FLAGS     := -Wall -Wextra -Werror -std=c++98
SRCS      := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp\

OBJS      := $(SRCS:.cpp=.o)

.cpp@.o:
	@${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created ✔️"

all:		${NAME}

clean:
			@ ${RM} $(OBJS)

fclean:		clean
			@ rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
