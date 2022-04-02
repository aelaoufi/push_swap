NAME = push_swap

SRCS = push_swap.c helpers.c lists.c permutations.c

FLAG = -Werror -Wextra -Wall

OBJ := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(FLAG) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(OBJ)

re: fclean all