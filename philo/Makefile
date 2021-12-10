NAME =	philo

SRC =	main.c				\
		utils/ft_atoi.c		\
		utils/ft_strlen.c	\
		utils/int_check.c	\
		utils/gettime.c		\
		utils/ft_calloc.c	\
		src/init.c			\
		src/routine.c		\

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)
	$(MAKE) clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re