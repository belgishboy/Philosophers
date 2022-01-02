NAME =	philo

SRC =	main.c				\
		utils/ft_atoi.c		\
		utils/ft_strlen.c	\
		utils/int_check.c	\
		utils/gettime.c		\
		src/init.c			\
		src/print.c			\
		src/routine.c		\
		src/actions.c		\

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=thread

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)
	$(MAKE) clean
	echo DO NOT RUN VALGRIND

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re