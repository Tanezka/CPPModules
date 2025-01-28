NAME      := megaphone
CC        := c++
FLAGS     := -Wall -Wextra -Werror -std=c++98
SRCS      := megaphone.cpp

OBJS      := $(SRCS:.cpp=.o)

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created ✔️"

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
